# CY4050 Numericals: Formulas, Questions and Solutions

Compiled from your handwritten notes, the graphite/Si slides and the earlier extended notes. Problems marked **(notes)** come from your handwritten pages, with the question reconstructed from the answer you wrote. Problems marked **(added)** are extrapolated practice. Use F = 96500 C/mol and λ = 1.54056 Å unless a question says otherwise.

## 1. Formulas and constants

| Topic | Formula |
| --- | --- |
| Charge | Q = i·t |
| Energy | Wh = V × Ah |
| Specific energy | Wh/kg = V\_nominal × capacity / mass |
| Series / parallel | V = n\_s V\_cell; Q = n\_p Q\_cell |
| Cell voltage | E\_cell = E\_cathode − E\_anode |
| Free energy | ΔG = −nFE |
| Theoretical capacity | Q\_th (mAh/g) = nF / (3.6 M) |
| Practical capacity | Q = i·t / (3600 m) (i in mA, t in s, m in g) |
| Li fraction cycled | x = Q\_practical / Q\_th |
| Mixed anode | Q = Σ (weight fraction × Q\_th) |
| Alloy capacity LiₓM | Q = x F / (3.6 M\_host) |
| Balancing mass | m\_anode = Q\_cathode / Q\_anode |
| C-rate current | I = C-rate × Q × mass; time = 1 / C-rate |
| Bragg's law | nλ = 2d sinθ, so d = λ / (2 sinθ) |
| Layered oxide | c = 3 d(003) |
| Coulombic efficiency | CE = Q\_discharge / Q\_charge |
| Li lost | n\_Li = Q\_loss (mAh) × 3.6 / 96500 |
| Diffusion time | t ≈ L² / D |
| Arrhenius ratio | k₂/k₁ = exp\[(E\_a/R)(1/T₁ − 1/T₂)\] |

**Atomic masses (g/mol):** Li 6.94, C 12.01, O 16.00, Al 26.98, Si 28.09, P 30.97, S 32.06, Ti 47.87, Mn 54.94, Fe 55.85, Co 58.93, Ni 58.69, Sn 118.71.

**Constants:** F = 96500 C/mol (96485 exact), R = 8.314 J/(mol·K), 1 mAh = 3.6 C, 1 Å = 0.1 nm.

**Problem format:** each problem gives the question, the working and a boxed-style answer in bold.

## A. Pack, voltage and energy problems

**A1 (notes). Pack of 5 cells.** Five Li-ion cells of 3.7 V and 3400 mAh are connected in series. Find (1) the pack voltage, (2) the capacity and (3) the energy.

- Series adds voltage: V = 5 × 3.7 = **18.5 V**.
- Series keeps capacity: **3400 mAh** (3.4 Ah).
- Energy = 18.5 × 3.4 = **62.9 Wh**.

**A2 (notes). Pack of 12 cells.** A pack is built from 3.7 V, 3.4 Ah cells. Your answers were 4, 3, 12 and 150.96 Wh, which reads as a 4s3p pack: (1) cells in series, (2) strings in parallel, (3) total cells, (4) energy. The question is reconstructed from those answers.

- Series count = **4**, parallel count = **3**, total = 4 × 3 = **12 cells**.
- Pack voltage = 4 × 3.7 = 14.8 V. Pack capacity = 3 × 3.4 = 10.2 Ah.
- Energy = 14.8 × 10.2 = **150.96 Wh**. Check: 12 × (3.7 × 3.4) = 12 × 12.58 = 150.96 Wh.

**A3 (added). Specific energy.** A 3.6 V, 5 Ah cell weighs 90 g. Find its specific energy.

- Energy = 3.6 × 5 = 18 Wh. Mass = 0.090 kg.
- Specific energy = 18 / 0.090 = **200 Wh/kg**.

**A4 (added). 4s2p pack.** Cells are 3.6 V, 5 Ah. Find voltage, capacity and energy.

- V = 4 × 3.6 = 14.4 V. Q = 2 × 5 = 10 Ah.
- Energy = 14.4 × 10 = **144 Wh**.

**A5 (added). Cell voltage from electrode potentials.** E\_cathode = 4.0 V and E\_anode = 0.2 V, both vs Li⁺/Li. Find E\_cell.

- E\_cell = E\_cathode − E\_anode = 4.0 − 0.2 = **3.8 V**, which matches the LiCoO₂ ‖ LiₓC₆ value in your notes.

## B. Theoretical capacity of cathodes

Use Q\_th = nF / (3.6 M) with n = 1 Li per formula unit unless stated.

**B1 (notes). LiCoO₂.** Find Q\_th, then the capacity when only 0.5 Li is drawn.

- M = 6.94 + 58.93 + 2(16.00) = 97.87 g/mol.
- Q\_th = 96500 / (3.6 × 97.87) = 96500 / 352.3 = **274 mAh/g**.
- With x = 0.5, Q = 0.5 × 274 = **137 mAh/g**.

**B2 (notes). LiFePO₄.** Find Q\_th.

- M = 6.94 + 55.85 + 30.97 + 4(16.00) = 157.76 g/mol.
- Q\_th = 96500 / (3.6 × 157.76) = **170 mAh/g**.

**B3 (notes). LiNi₁/₃Mn₁/₃Co₁/₃O₂ (NMC111).** M = 96.48 g/mol and n = 1. Find Q\_th, and the fraction of Li used if 165 mAh/g is measured at C/30.

- Q\_th = 96500 / (3.6 × 96.48) = **278 mAh/g**.
- x = 165 / 278 = **0.59**.

**B4 (notes). NMC811 (LiNi₀.₈Mn₀.₁Co₀.₁O₂).** Find M and Q\_th.

- M = 6.94 + 0.8(58.69) + 0.1(54.94) + 0.1(58.93) + 32 = 6.94 + 46.95 + 5.49 + 5.89 + 32 = **97.28 g/mol**.
- Q\_th = 1 × 96500 / (3.6 × 97.28) = **275.5 mAh/g**.

**B5 (added). NMC532 (LiNi₀.₅Co₀.₂Mn₀.₃O₂).**

- M = 6.94 + 0.5(58.69) + 0.2(58.93) + 0.3(54.94) + 32 = 96.55 g/mol.
- Q\_th = 96500 / (3.6 × 96.55) = **277.6 mAh/g**.

**B6 (added). NMC622 (LiNi₀.₆Mn₀.₂Co₀.₂O₂).**

- M = 6.94 + 0.6(58.69) + 0.2(54.94) + 0.2(58.93) + 32 = 96.93 g/mol.
- Q\_th = 96500 / (3.6 × 96.93) = **276.5 mAh/g**.

**B7 (added). LiMn₂O₄ (LMO).**

- M = 6.94 + 2(54.94) + 4(16.00) = 180.82 g/mol.
- Q\_th = 96500 / (3.6 × 180.82) = **148 mAh/g**.

**B8 (added). LiNi₀.₅Mn₁.₅O₄ (LNMO).**

- M = 6.94 + 0.5(58.69) + 1.5(54.94) + 64 = 182.70 g/mol.
- Q\_th = 96500 / (3.6 × 182.70) = **146.7 mAh/g**.

**B9 (added). NCA (LiNi₀.₈Co₀.₁₅Al₀.₀₅O₂).**

- M = 6.94 + 0.8(58.69) + 0.15(58.93) + 0.05(26.98) + 32 = 96.08 g/mol.
- Q\_th = 96500 / (3.6 × 96.08) = **279 mAh/g**.

**B10 (added). Fraction of Li removed in NMC811.** A cell delivers 205 mAh/g.

- x = 205 / 275.5 = **0.74**, so 0.26 Li remains in the structure.

**B11 (notes). Li left in LiCoO₂.** In LiCoO₂ → Li₁₋ₓCoO₂ + xLi⁺ + xe⁻, Q\_th = 274 and Q\_ex = 137 mAh/g. Find x and the Li remaining.

- x = 137 / 274 = **0.5**, so **0.5 Li remains** (Li₀.₅CoO₂).

**B12 (added). Why theoretical capacities are so similar.** Compare B1, B3, B4, B5, B6 and B9. All are about 274–279 mAh/g because the molar masses lie between 96 and 98 g/mol. The practical difference comes from how much Li can be removed before the structure fails.

## C. Anodes: graphite, Si, Sn, mixed anodes and balancing

**C1 (notes). Graphite.** One Li per 6 C (LiC₆), so n = 1/6 and M = 12.01. Find Q\_th.

- Q\_th = (1/6)(96500) / (3.6 × 12.01) = 16083 / 43.24 = **372 mAh/g** (your notes: 371.99).

**C2 (notes). Stage 4, LiC₇₂.** Find the capacity of the LiC₇₂ stage, and then the other stages.

- Q = (1/72)(96500) / (12.01 × 3.6) = **31 mAh/g**.
- By the same rule Q = 372 / stage: stage 3 (LiC₃₆) = **62**, stage 2 (LiC₁₂) = **186**, stage 1 (LiC₆) = **372 mAh/g**.

**C3 (notes). Li metal.** Li → Li⁺ + e⁻. Find Q\_th.

- Q\_th = 96485 / (3.6 × 6.94) = **3861.9 mAh/g**. Using 96500 gives 3862.5, and your notes round it to about 4000.

**C4 (notes). Silicon.** 15Li + 4Si → Li₁₅Si₄, so n = 15/4 per Si. Find Q\_th.

- Q\_th = (15/4)(96500) / (3.6 × 28.09) = 361875 / 101.1 = **3579 mAh/g**.

**C5 (notes). Tin.** Sn + 4.4Li → Li₄.₄Sn. Find Q\_th.

- On the Sn mass: Q = 4.4 × 96500 / (3.6 × 118.71) = 424600 / 427.4 = **994 mAh/g**.
- ⚠️ Your notes show 537.286 = 3.6 × 149.246 (the lithiated alloy mass), which is the denominator, not the answer. Dividing, 424600 / 537.286 ≈ **790 mAh/g** is the value on the alloy-mass basis.
- Use the Sn basis (994) for comparison with Si (3579), which is also on the host mass.

**C6 (notes). Si–Sn alloy anode.** The anode is 60% Si and 40% Sn by weight. Find Q\_th.

- Q = 0.6(3579) + 0.4(994) = 2147 + 398 = **2545 mAh/g**.

**C7 (notes). Si/graphite composite.** Find Q\_th for 5% Si and 95% graphite. Then for 10% Si and 90% graphite (added).

- 5/95: 0.05(3579) + 0.95(372) = 178.95 + 353.4 = **532 mAh/g**.
- 10/90: 0.10(3579) + 0.90(372) = 357.9 + 334.8 = **692.7 mAh/g**.

**C8 (notes). Capacity balancing against 1 g LiCoO₂ (274 mAh).** Find the anode mass for Li₁₅Si₄ and for graphite.

- Li₁₅Si₄: 274 / 3579 = 0.077 g (your notes: 0.07 g). Total = 1 + 0.077 ≈ **1.07 g**.
- Graphite: 274 / 372 = 0.737 g. Total = 1 + 0.737 ≈ **1.73 g**.
- The high-capacity anode makes a thinner, lighter electrode, so energy density rises and charging is faster.

**C9 (added). Capacity at each Li–Si phase step.** Using Q = 954 x mAh/g for LiₓSi (954 = 96500 / (3.6 × 28.09)), find the capacity at x = 1.71, 2.33, 3.25 and 4.4 (the room-temperature slide steps).

| x in LiₓSi | Capacity (mAh/g) |
| --- | --- |
| 1.71 | 954 × 1.71 ≈ 1632 |
| 2.33 | 954 × 2.33 ≈ 2223 |
| 3.25 | 954 × 3.25 ≈ 3101 |
| 3.75 | 954 × 3.75 ≈ 3579 |
| 4.4 | 954 × 4.4 ≈ 4199 |

**C10 (added). Anode mass with N/P = 1.1.** A cell has 2 g LiFePO₄ at 150 mAh/g practical and a graphite anode at 350 mAh/g practical. Find the graphite mass.

- Cathode capacity = 2 × 150 = 300 mAh. Anode capacity needed = 1.1 × 300 = 330 mAh.
- Mass = 330 / 350 = **0.94 g**.

**C11 (added). Li needed to lithiate 1 g of Si to Li₁₅Si₄.**

- n(Si) = 1 / 28.09 = 0.0356 mol. n(Li) = 3.75 × 0.0356 = 0.1335 mol.
- m(Li) = 0.1335 × 6.94 = **0.93 g**. The electrode mass rises by **93%**.

**C12 (added). Mass gain of Sn on lithiation to Li₄.₄Sn.**

- m(Li) per g Sn = 4.4 × 6.94 / 118.71 = 0.257 g, so the gain is **25.7%**.

**C13 (added). Li₄Ti₅O₁₂ → Li₇Ti₅O₁₂.**

- M = 4(6.94) + 5(47.87) + 12(16.00) = 459.1 g/mol, n = 3.
- Q\_th = 3 × 96500 / (3.6 × 459.1) = **175 mAh/g**.

**C14 (added). First-cycle efficiency of Si (slide).** About 3600 mAh/g goes in and 2700 mAh/g comes out.

- Efficiency = 2700 / 3600 = **75%**. Irreversible loss = 900 mAh/g.

## D. C-rate, current and overcharge

I = C-rate × Q × mass, and time = 1 / C-rate. In your notes the current needed to reach full theoretical capacity is a function of C-rate and mass, using Q\_th.

**D1 (notes). Graphite current.** Find the current for 1C when the graphite mass is (a) 1 mg and (b) 1 g.

- (a) Capacity of 1 mg = 0.372 mAh, so 1C: I = **0.372 mA**.
- (b) Capacity of 1 g = 372 mAh, so 1C: I = **372 mA**.
- General: I = C-rate × 0.372 mAh per mg.

**D2 (notes). Overcharge check.** A LiCoO₂ test gives Q = 400 mAh/g. Is that reasonable? The inputs in your notes are not clear (2 mA and 200 appear), so this uses the result you wrote.

- Compare with Q\_th = 274 mAh/g. Since 400 > 274, the cell is **overcharged** (above the voltage limit).
- Excess charge cannot come from Li extraction (x cannot exceed 1), so it comes from side reactions and O₂ loss.
- An example that gives this number: 2 mA for 100 h on a 0.5 g electrode, Q = 2 × 100 / 0.5 = 400 mAh/g (added).

**D3 (added). Practical capacity from a test.** A 5 mg graphite electrode is discharged at 0.2 mA and reaches the cut-off after 22320 s. Find Q.

- Q = i·t / (3600 m) = 0.2 × 22320 / (3600 × 0.005) = 4464 / 18 = **248 mAh/g**.
- This is 67% of 372, so about 0.67 Li per 6 C was used.

**D4 (added). 3.4 Ah cell currents.**

| C-rate | Current (A) | Ideal time |
| --- | --- | --- |
| C/2 | 1.7 | 2 h |
| 1C | 3.4 | 1 h |
| 2C | 6.8 | 0.5 h |
| C/30 | 0.113 | 30 h |

**D5 (added). Coin cell currents.** 8 mg of NMC811 is cycled at a practical 200 mAh/g. Find the current at 0.5C and 2C, and the time at C/5.

- Capacity = 8 mg × 0.2 mAh/mg = 1.6 mAh.
- 0.5C: I = **0.8 mA**. 2C: I = **3.2 mA**. C/5: t = **5 h**.

**D6 (added). Overcharge by capacity.** A 10 mg LiCoO₂ electrode is charged at 1 mA for 3 h. Compute the capacity and comment.

- Q = 1 × 3 / 0.010 = **300 mAh/g**, which is above 274 mAh/g, so the cell is overcharged.

**D7 (added). NMC111 at C/30.** Find the current per gram of NMC111 at C/30 using Q\_th = 278 mAh/g, and the ideal time.

- I = (1/30) × 278 = **9.3 mA per g**. Time = **30 h**.
- The measured 165 mAh/g is only 59% of Q\_th, because the voltage window stops charging first.

**D8 (added). Graphite at 2C.** Find the current for 1 g of graphite at 2C and the time.

- I = 2 × 372 = **744 mA**. Time = 0.5 h.
- At this rate Li⁺ may not diffuse in time, so plating and dendrites are a risk (see section F).

## E. XRD and lattice problems

Bragg's law: nλ = 2d sinθ. For n = 1, d = λ / (2 sinθ). Always **halve 2θ** to get θ. Take λ = 1.54056 Å (your notes wrote this with a degree sign, but it is a length in Å).

**E1 (notes). d-spacing from the (003) peak.** The (003) peak of LiCoO₂ is at 2θ = 18.80°.

- θ = 9.40°, sinθ = 0.1633.
- d = 1.54056 / (2 × 0.1633) = **4.72 Å**.

**E2 (notes). c parameter.** For the (003) reflection, d = c/3. Find c.

- c = 3 × 4.72 = **14.16 Å**.
- ⚠️ Your notes show 14.3 Å. 3 × 4.72 gives 14.16 Å, so check which d you used (14.3 needs d ≈ 4.77 Å). Your reference value in the notes for (003) is 4.67 Å, which gives c = 14.0 Å.

**E3 (notes). Peak shift on charging.** The (003) peak moves from 2θ = 18.70° to 18.10°. Find (i) the two d values, (ii) the percent change, and (iii) what it means.

- (i) 18.70°: θ = 9.35°, sinθ = 0.1625, d = **4.741 Å**. 18.10°: θ = 9.05°, sinθ = 0.1572, d = **4.897 Å** (your notes: 4.897).
- (ii) (4.897 − 4.741) / 4.741 × 100 = **3.3%**. ⚠️ Your notes show 2.64%, which does not match these d values.
- (iii) c has increased, as oxide–oxide layers repel after Li⁺ leaves. The structure goes from O₃ to O₃′. A lower 2θ always means a larger d.

**E4 (added). 2θ from a known d.** Find the (003) peak position for d = 4.67 Å.

- sinθ = 1.54056 / (2 × 4.67) = 0.1649, so θ = 9.49° and **2θ = 18.99°**. Then c = 3 × 4.67 = **14.0 Å**.

**E5 (added). Peak positions for the graphite series.** Use 2θ = 2 arcsin(λ / 2d).

| Phase | d (Å) | sinθ | 2θ (°) |
| --- | --- | --- | --- |
| Graphite (002) | 3.354 | 0.2297 | 26.6 |
| LiC₁₂ (002) | 3.51 | 0.2194 | 25.4 |
| LiC₆ (001) | 3.70 | 0.2082 | 24.0 |

The peak moves left as Li goes in. The 002 reflection of graphite fades and the 001 reflection of LiC₆ appears, as in your notes.

**E6 (added). Graphite expansion from XRD.** The graphite (002) peak is at 26.5° and the LiC₆ (001) peak is at 24.0°. Find the d-spacings and the percent expansion along c.

- 26.5°: θ = 13.25°, d = 1.54056 / (2 × 0.2292) = **3.36 Å**.
- 24.0°: θ = 12.0°, d = 1.54056 / (2 × 0.2079) = **3.70 Å**.
- Expansion = (3.70 − 3.36) / 3.36 = **10%**, in line with the roughly 10% swelling seen in dilatometry.

**E7 (added). Unknown layered oxide.** The (003) peak is at 2θ = 18.90°. Find d and c.

- θ = 9.45°, sinθ = 0.1642, d = **4.69 Å**, c = 3d = **14.08 Å**.

**E8 (added). Predict the new peak.** After charging, c of LiCoO₂ increases by 3% from d = 4.72 Å. Where does the (003) peak move?

- New d = 4.72 × 1.03 = 4.862 Å.
- sinθ = 1.54056 / (2 × 4.862) = 0.1584, so θ = 9.12° and **2θ = 18.2°**, which is a shift of about 0.6° to lower angle.

## F. Efficiency, thermodynamics and kinetics

**F1 (notes). Li–S cell voltage.** (−): 2Li → 2Li⁺ + 2e⁻. (+): ⅛S₈ + 2Li⁺ + 2e⁻ → Li₂S. Given ΔG = −432 kJ/mol, find E.

- n = 2. E = −ΔG / (nF) = 432000 / (2 × 96485) = **2.24 V**.

**F2 (notes). Coulombic efficiency and Li lost.** A cell charges at 150 mAh and discharges at 140 mAh. Find CE and the Li lost.

- CE = 140 / 150 = **93.3%**.
- Lost charge = 10 mAh = 36 C. n(Li) = 36 / 96500 = 3.7 × 10⁻⁴ mol, so m = 3.7 × 10⁻⁴ × 6.94 = **2.6 mg Li**.
- The lost Li⁺ goes to side reactions that form a resistive layer and cause Joule heating.

**F3 (added). Larger loss.** In cycle 1 a cell charges 200 mAh and discharges 170 mAh. Find CE and the Li lost.

- CE = 170 / 200 = **85%**.
- Loss = 30 mAh = 108 C, so n(Li) = 1.12 × 10⁻³ mol and m = **7.8 mg Li**.

**F4 (added). Retention from CE.** CE is steady at 99.8%. Estimate retention after 200 cycles using retention ≈ CEⁿ. Then compare 99.9%, 99.5% and 99% at 100 cycles.

- 0.998²⁰⁰ = **0.67**, so about 67%.
- 100 cycles: 0.999¹⁰⁰ = **90%**, 0.995¹⁰⁰ = **61%**, 0.99¹⁰⁰ = **37%**.

**F5 (added). Free energy from a cell voltage.** Find ΔG for (a) LiCoO₂ ‖ Li at 4.0 V, (b) LiCoO₂ ‖ graphite at 3.8 V and (c) a 3.7 V cell, with n = 1.

- (a) ΔG = −96485 × 4.0 = **−386 kJ/mol**.
- (b) ΔG = −96485 × 3.8 = **−367 kJ/mol**.
- (c) ΔG = −96485 × 3.7 = **−357 kJ/mol**.
- The 19 kJ/mol difference between (a) and (b) is the "not that much loss" in your notes from using graphite instead of Li.

**F6 (added). Lead–acid.** E° = 2.01 V with n = 2. Find ΔG.

- ΔG = −2 × 96485 × 2.01 = **−388 kJ/mol**.

**F7 (added). Why aqueous electrolytes are limited.** Water splits at 1.23 V (H₂O → H₂ + ½O₂, n = 2). Find the free energy and the maximum useful cell voltage idea.

- ΔG = 2 × 96485 × 1.23 = **237 kJ/mol** must be supplied to split water.
- A cell above about 1.23 V thermodynamically decomposes water, so a 3.7–4 V Li-ion cell needs an organic electrolyte. A lower voltage means lower energy density.

**F8 (added). Material-level specific energy.** NMC811 averages 3.8 V vs Li and delivers 205 mAh/g. Find the energy per kg of cathode material.

- Energy = 3.8 × 205 = **779 Wh/kg** (mAh/g equals Ah/kg).

**F9 (added). Diffusion time.** Li⁺ must travel L = 5 µm in a solid with D = 10⁻¹⁰ cm²/s (assumed typical). Find t, and the effect of L = 10 µm.

- L = 5 × 10⁻⁴ cm. t = L² / D = 2.5 × 10⁻⁷ / 10⁻¹⁰ = 2500 s ≈ **42 min**.
- L = 10 µm gives t = 10⁻⁶ / 10⁻¹⁰ = 10⁴ s ≈ **2.8 h**, which is 4× longer for 2× the distance.
- A 1C rate lasts 1 h, so a 10 µm path cannot keep up, and Li⁺ plates on the surface (dendrites).

**F10 (added). Temperature effect on rate.** A process has E\_a = 40 kJ/mol. Compare the rate at 25 °C with 0 °C.

- (E\_a/R)(1/273.15 − 1/298.15) = 4811 × 3.07 × 10⁻⁴ = 1.48.
- Rate ratio = e^1.48 ≈ **4.4**, so the process is about 4.4× slower at 0 °C. This is why fast charging in the cold causes plating.

## G. Extra practice set with answers (added)

These use the same formulas on new materials and setups. Try each before reading the working.

**G1. LiNiO₂.** Find Q\_th (n = 1).

- M = 6.94 + 58.69 + 32 = 97.63. Q\_th = 96500 / (3.6 × 97.63) = **274.5 mAh/g**.

**G2. LiMnO₂.** Find Q\_th (n = 1).

- M = 6.94 + 54.94 + 32 = 93.88. Q\_th = 96500 / (3.6 × 93.88) = **285.5 mAh/g**.

**G3. Sodium metal.** Na → Na⁺ + e⁻. Find Q\_th and compare with Li.

- Q\_th = 96500 / (3.6 × 22.99) = **1166 mAh/g**, about 30% of Li (3862 mAh/g), because Na is heavier.

**G4. Graphite on the LiC₆ basis.** Find Q\_th using n = 1 and M of the formula unit 6 × 12.01 = 72.06.

- Q\_th = 96500 / (3.6 × 72.06) = **372 mAh/g**, the same as using n = 1/6 with M = 12.01.

**G5. Composition for a target capacity.** What weight fraction of Si in a Si/graphite composite gives 1000 mAh/g?

- f(3579) + (1 − f)(372) = 1000, so f = (1000 − 372) / (3579 − 372) = 628 / 3207 = **0.196**, about 19.6 wt% Si.

**G6. Building a 1 kWh pack.** Cells are 3.6 V and 3 Ah. How many cells are needed, and what is a suitable layout?

- Cell energy = 3.6 × 3 = 10.8 Wh. Cells = 1000 / 10.8 = 92.6, so about **93 cells**.
- A 12s8p pack uses 96 cells: V = 12 × 3.6 = 43.2 V, Q = 8 × 3 = 24 Ah, energy = **1037 Wh**.

**G7. Discharge time.** A 3.4 Ah cell is discharged at 0.5 A. Find the time and the C-rate.

- t = 3.4 / 0.5 = **6.8 h**. C-rate = 0.5 / 3.4 = **0.147C** (about C/6.8).

**G8. Peak from a given d.** A reflection has d = 2.0 Å. Find 2θ.

- sinθ = 1.54056 / (2 × 2.0) = 0.3851, θ = 22.65°, so **2θ = 45.3°**.

**G9. Li taken up by graphite.** How much Li does 1 g of graphite store when it becomes LiC₆?

- n(C) = 1 / 12.01 = 0.0833 mol, n(Li) = 0.0833 / 6 = 0.01388 mol.
- m(Li) = 0.01388 × 6.94 = **0.096 g**, a mass gain of **9.6%**.

**G10. Charging time of a Si electrode.** A 2 mg Si electrode is lithiated to 3579 mAh/g at 0.5 mA. Find the time.

- Capacity = 2 mg × 3.579 mAh/mg = 7.16 mAh. Time = 7.16 / 0.5 = **14.3 h**.

**G11. Average fade rate.** A cell drops from 150 to 120 mAh/g over 100 cycles. Find the retention and the equivalent per-cycle retention.

- Retention = 120 / 150 = **80%**.
- Per cycle = 0.8^(1/100) = **0.99777**, so an average CE-like retention of about **99.78%**.

**G12. Which anode saves more mass?** Compare the mass of graphite and of Si (3579 mAh/g) needed to store 500 mAh.

- Graphite: 500 / 372 = **1.34 g**. Si: 500 / 3579 = **0.14 g**.
- Si needs about **9.6× less** active mass, but it swells about 300% in volume, so mass saved is offset by cracking and fade.

**Exam method:** write the formula, list M and n, convert units (mA, h, g, Å), compute, then compare with a known limit (274 for LCO, 372 for graphite, 3579 for Si) to catch mistakes.
