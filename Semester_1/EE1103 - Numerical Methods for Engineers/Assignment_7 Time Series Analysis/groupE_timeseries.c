/*
Developer(s) : EE24B066 , EE24B093 , EE24B053
Date         : 23 September 2024
Purpose      : To generate a data file of lorentzian peaks with noise and analyze the peaks , their widths at half maximum and their 
               time periods (distance between peaks) , and also analyze a data file and find average and standard deviations  
               of the widths and time periods.
Input(s)     : Either
               I - 1 integer M (number of peaks) , 2 doubles T(Time period) and a(width of peak)
               II - Name of data file in string format
Output(s)    : average of Time period T_avg , average of width a_avg , standard deviation of Time period T_stdev , 
               standard deviation of width a_stdev
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define N 1000000                                       //defining variables to be used
#define DIV (5*(T/a))

void lorentz(int M, double T, double a, double* data);     //defining function to be used in main() and defined later
void box_muller(double* rand1, double*rand2);
void smooth(double* data, int len);

int main(int argc, char **argv) 
{
	if(argc == 4)                                           // if there are 3 inputs
    {   
        srand((int)time(NULL));                             //generating random seed

        int M = atoi(argv[1]);
        double T = atof(argv[2]);                           //taking inputs from user
        double a = atof(argv[3]);
        double dx = T/DIV;

        double* data = malloc(M*DIV*sizeof(double));        //allocating memory

		lorentz(M, T, a, data);                             //generating the data
        smooth(data, M*DIV);                                //smoothening the generated data

        double* T_temp = malloc(M*sizeof(double));          //allocating memory to all arrays to be used
        double* a_val = malloc(M*sizeof(double));
        double* T_val = malloc((M-1)*sizeof(double));
        double T_avg, a_avg, T_stdev, a_stdev;
        for(int i = 0; i < M; i++)
        {
            int j = 0;
            while(data[j+(int)(i*DIV)] < 0.5)               //finding left side half maximum point
                j++;
            double t1 = dx * (j + i * DIV);

            while(data[j + (int)(i * DIV)] > 0.5)           //finding right side half maximum point
                j++;
            double t2 = dx * (j + i *DIV);

            a_val[i] = t2 - t1 ;                            //Full width at half maximimum
            T_temp[i] = t2;
        }

	    for(int i = 0; i < M - 1; i++)
        {
	    	T_val[i] = T_temp[i + 1] - T_temp[i];           //Time between 2 consecutive peaks
	    	T_avg += T_val[i];
	    	a_avg += a_val[i];                              //summing for average
	    	T_stdev += pow(T_val[i], 2);                    //summing squares for standard deviation
	    	a_stdev += pow(a_val[i], 2);
	    }
	    T_avg = T_avg / (M - 1);
	    a_avg = (a_avg + a_val[M - 1]) / M;                             //formulae for standard deviation and average
	    T_stdev = T_stdev / (M - 1) - pow(T_avg, 2);
	    a_stdev = (a_stdev + pow(a_val[M - 1], 2)) / M - pow(a_avg, 2);

	    printf("%f , %f , %f , %f \n", T_avg, a_avg, T_stdev, a_stdev); //printing output
        
        free(data);
        free(T_temp);
        free(a_val);
        free(T_val);                                        //freeing allocated memory

	    return 0;
	}
    else if (argc == 2)                                     //if there is one input
    {
        FILE *fptr = fopen(argv[1], "r");                   //opening the file in read mode
        if (!fptr)
        {
            perror("Error opening file");                   //error if file is not opened
            return 1;
        }
        double period_avg , period_stdev , voltwid_avg , voltwid_stdev;     //defining variables to be used
        int total_count = 0 ;

            double *volt = (double*)calloc(N , sizeof(double));             //allocating memory

            char buffer[1024];
            int row = 0;
            int count = 0;

            while (fgets(buffer, sizeof(buffer), fptr)) 
            {
                if (row == 0)                                               //skipping header 
                {
                    row++;
                    continue;
                }

                char *data_points = strtok(buffer, ", ");                   //taking care of delimiter
                for (int i = 0; i < 2; i++) 
                {
                    if (i == 1 && data_points)
                    {
                        volt[count] = atof(data_points);                    //getting the inputs from data file
                        count++;
                    }
                    data_points = strtok(NULL, ", ");
                }
            }
            double volt_avg;
            int count1 = 0 ;
            for(int i = 0 ; i < N ; i++ )
            {
                if (volt)
                    count1++;                                               //finding the number of points in file
            }
            double *voltwid_val = (double*)calloc(N , sizeof(double));      //allocating memory
            int *S_temp = (int*)calloc(N , sizeof(int));                    

            int y = 0;
            double *volt_smooth = (double*)calloc(ceil(N/10) ,sizeof(double));
            for (int i = 10 ; i < floor(count1/10) ; i++)
            {
                double volt_sum = 0 ;
                for(int j = 0 ; j < 10 ; j++)                               //smoothening the data
                    volt_sum = volt[i*10 + j] ;
                volt_smooth[i] = volt_sum / 10 ;
            }
            for(int k = 51; k < ceil(count1/10) - 51 ; k++)
            {
                int x ;
                double volt_max ;
                int end = 0 ;

                for (int m = 1 ; m < 50 ; m++)
                {
                    if (volt_smooth[k+m] > volt_smooth[k] || volt_smooth[k-m] > volt_smooth[k])             //locating the peaks
                    {
                        end += 1 ;
                        break;
                    }
                }
                if (end == 0)
                {
                    x = k ;
                    volt_max = volt_smooth[k];                                          //using location of peaks to find width
                    int x1 = x ;
                    int x2 = x ;
                    while (volt_smooth[x1] > volt_max / 2)
                        x1-- ;
                    while (volt_smooth[x2] > volt_max / 2)
                        x2++ ;
                    
                    voltwid_val[y] = (x2 - x1) ;                                        //full width at half maximum
                    S_temp[y] = x;

                    y++ ;
                }
            }
            for (int i = 0; i < y - 1 ; i++)
            {
                period_avg += S_temp[i + 1] - S_temp[i] ;                       //calculating distance between peaks
                period_stdev += pow(S_temp[i + 1] - S_temp[i] , 2) ;            //adding squares to standard deviation

                voltwid_avg += voltwid_val[i];
                voltwid_stdev += pow(voltwid_val[i], 2) ;
            }
            voltwid_avg += voltwid_val[y - 1] ;
            voltwid_stdev += pow(voltwid_val[y - 1], 2) ;

        free(volt);
        free(S_temp);                                                           //freeing allocated memory       
        free(voltwid_val);
        fclose(fptr);
        free(volt_smooth);

        period_avg /= (y - 1) ;
        period_stdev /= (y - 1) ;

        voltwid_avg = voltwid_avg /y ;
        voltwid_stdev = sqrt(voltwid_stdev/y - pow(voltwid_avg, 2));

        printf("%f , %f , %f , %f \n", period_avg , voltwid_avg , period_stdev , voltwid_stdev) ;       //printing the output
        return 0 ;
    }
}

void box_muller(double* rand1, double* rand2)                                      
{
	double u1 , u2 ;
	u1 = sqrt(-2*log(*rand1))*cos(2*M_PI*(*rand2));                             //formulae of box_muller transform
	u2 = sqrt(-2*log(*rand2))*sin(2*M_PI*(*rand1));
    *rand1 = u1 ;
    *rand2 = u2 ;
}

void smooth(double* data, int len)                                              //smoothening of the generated data
{
	int span = 6;

	for(int i = span/2; i < len-span/2; i++)
    {
		double temp = 0;

		for(int j = 0; j < span; j++)
        {
			temp += data[i-(span/2)+j];
		}

		data[i] = temp/span;
	}
}

void lorentz(int M, double T, double a, double* data)                           //generating data with lorentzian peaks 
{
	double t = 0;

	for(int i = 0; i < M; i++)
    {
		double eps_T = rand()/(double)(RAND_MAX);
		double eps_a = rand()/(double)(RAND_MAX);
		box_muller(&eps_T, &eps_a);

		eps_T = T*eps_T/60;
		eps_a = a*(1 + eps_a/60);

		for(int j=0; j < DIV; j++)
        {
			double n = rand()/(double)(RAND_MAX);
			double x = rand()/(double)(RAND_MAX);
			box_muller(&n, &x);
			n = n/30;

			data[j+(int)(i*DIV)] = pow(eps_a,2)/(pow(t-(i+0.5)*T-eps_T,2)+pow(eps_a,2)) + n;
			t += T/DIV;
		}
	}
}