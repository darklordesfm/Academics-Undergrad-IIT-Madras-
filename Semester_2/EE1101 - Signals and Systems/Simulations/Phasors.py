import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib import animation
import matplotlib as mpl
from scipy.interpolate import splprep, splev
import matplotlib.patheffects as path_effects

# Set up the figure with a black background
plt.style.use('dark_background')
fig, ax = plt.subplots(figsize=(10, 6))
ax.set_facecolor('black')
fig.patch.set_facecolor('black')

# Create the text path for "EE24B093"
plt.rcParams['font.family'] = 'monospace'
temp_fig, temp_ax = plt.subplots()
text = temp_ax.text(0.5, 0.5, "EE24B093", ha='center', va='center', fontsize=30)
plt.close(temp_fig)

# Get path data for the text
path = text.get_path()
vertices = path.vertices.copy()
codes = path.codes.copy()

# Scale and center the text
vertices[:, 0] = vertices[:, 0] - np.mean(vertices[:, 0])
vertices[:, 1] = vertices[:, 1] - np.mean(vertices[:, 1])
scale = 4.0 / max(np.ptp(vertices[:, 0]), np.ptp(vertices[:, 1]))
vertices = vertices * scale

# Convert path to a series of points
x_points = []
y_points = []

for i in range(len(vertices)):
    if i == 0 or codes[i] == 1:  # Move operation
        if i > 0:  # Add a break between segments
            x_points.append(None)
            y_points.append(None)
        x_points.append(vertices[i, 0])
        y_points.append(vertices[i, 1])
    else:
        x_points.append(vertices[i, 0])
        y_points.append(vertices[i, 1])

# Generate a more uniform path with more points for smoother animation
path_points = []
current_segment = []

for i in range(len(x_points)):
    if x_points[i] is None:
        if current_segment:
            path_points.append(np.array(current_segment))
            current_segment = []
    else:
        current_segment.append([x_points[i], y_points[i]])

if current_segment:
    path_points.append(np.array(current_segment))

# Resample each segment to get more uniform points
resampled_x = []
resampled_y = []

for segment in path_points:
    if len(segment) < 2:
        continue

    if len(segment) < 4:
        # Duplicate points for short segments
        segment = np.vstack([segment, segment, segment])

    # Use splprep for resampling
    tck, u = splprep([segment[:, 0], segment[:, 1]], s=0, k=min(3, len(segment) - 1))
    u_new = np.linspace(0, 1, 100)
    new_points = splev(u_new, tck)

    # Add the resampled points
    resampled_x.extend(new_points[0])
    resampled_y.extend(new_points[1])

    # Add None to separate segments
    resampled_x.append(None)
    resampled_y.append(None)

# Remove the last None
if resampled_x and resampled_x[-1] is None:
    resampled_x.pop()
    resampled_y.pop()

# Combine x and y into a single complex array for Fourier analysis
points = np.array([x for x, y in zip(resampled_x, resampled_y) if x is not None and y is not None])
points = points + 1j * np.array([y for x, y in zip(resampled_x, resampled_y) if x is not None and y is not None])

# Compute Fourier coefficients
N = len(points)
t = np.linspace(0, 1, N, endpoint=False)
dt = t[1] - t[0]

# Number of Fourier coefficients to compute
n_coefs = 150  # Adjust for more/less detail

# Frequencies for the Fourier series
freqs = np.fft.fftfreq(N, dt)
indices = np.argsort(np.abs(freqs))
indices = indices[1:]  # Skip the DC component

# Get the top frequencies for the best approximation
top_indices = indices[:n_coefs]
freqs = 2 * np.pi * freqs[top_indices]

# Compute the Fourier coefficients
coefs = np.fft.fft(points) / N
coefs = coefs[top_indices]

# Sort by frequency magnitude (ascending)
sort_indices = np.argsort(np.abs(freqs))
freqs = freqs[sort_indices]
coefs = coefs[sort_indices]

# Visualization setup
ax.set_xlim(-6, 6)
ax.set_ylim(-4, 4)
ax.set_aspect('equal')
ax.axis('off')

# Create line objects for phasors and the drawing
phasor_lines = [ax.plot([], [], 'w-', alpha=0.5, linewidth=0.8)[0] for _ in range(n_coefs)]
drawing_line, = ax.plot([], [], 'cyan', linewidth=2)
drawing_line.set_path_effects([path_effects.Stroke(linewidth=3, foreground='blue'),
                               path_effects.Normal()])

drawing_x = []
drawing_y = []
full_drawing_line, = ax.plot([], [], 'white', alpha=0.7, linewidth=1)
title = ax.text(0, 3.5, "Drawing 'EE24B093' with Phasors", fontsize=16,
                ha='center', color='white', weight='bold')

# Number of frames for the animation
n_frames = 300


def init():
    for line in phasor_lines:
        line.set_data([], [])
    drawing_line.set_data([], [])
    full_drawing_line.set_data([], [])
    return phasor_lines + [drawing_line, full_drawing_line]


def animate(i):
    # Current time in the parametrization
    time = i / n_frames

    # Initialize phasor start positions
    x_pos, y_pos = 0, 0

    # Compute each phasor
    for j, (freq, coef) in enumerate(zip(freqs, coefs)):
        # Previous position is the starting point for this phasor
        prev_x, prev_y = x_pos, y_pos

        # Current position is previous position plus the phasor contribution
        x_pos += np.abs(coef) * np.cos(freq * time + np.angle(coef))
        y_pos += np.abs(coef) * np.sin(freq * time + np.angle(coef))

        # Update the phasor line
        phasor_lines[j].set_data([prev_x, x_pos], [prev_y, y_pos])

    # Track the drawing
    drawing_x.append(x_pos)
    drawing_y.append(y_pos)

    # Display the current phasor position as the drawing point
    drawing_line.set_data([drawing_x[-min(50, len(drawing_x)):]], [drawing_y[-min(50, len(drawing_y)):]])

    # Display the full drawing so far
    full_drawing_line.set_data(drawing_x, drawing_y)

    return phasor_lines + [drawing_line, full_drawing_line]


# Create the animation
anim = FuncAnimation(fig, animate, init_func=init, frames=n_frames, interval=20, blit=True)

# To save the animation, uncomment the following line:
# anim.save('ee24b093_phasors.mp4', writer='ffmpeg', fps=30, dpi=100)

plt.tight_layout()
plt.show()