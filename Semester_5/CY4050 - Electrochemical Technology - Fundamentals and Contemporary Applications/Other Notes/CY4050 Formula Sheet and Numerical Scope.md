# CY4050 Formula Sheet and Numerical Problem Scope

Built from your notes, slides and the extended notes doc. Values use F = 96500 C/mol as in your notes.

## 1. Constants and unit conversions

| Quantity | Value | Note |
| --- | --- | --- |
| Faraday constant F | 96500 C/mol (96485 exact) | Your notes use 96500 |
| Gas constant R | 8.314 J/(mol·K) |  |
| Electron charge | 1.602 × 10⁻¹⁹ C |  |
| 1 Ah | 3600 C |  |
| 1 mAh | 3.6 C | Source of the 3.6 in Q\_th = nF/(3.6 M) |
| 1 Wh | 3600 J |  |
| 1 eV | 96.485 kJ/mol | A level 4 eV below Li⁺/Li means about 4 V |
| 1 nm | 10 Å | Graphite interlayer 0.3354 nm = 3.354 Å |
| Cu Kα wavelength λ | 1.54056 Å | Unit is Å, not degrees |
| Water splitting voltage | 1.23 V | Limit for aqueous electrolytes |
| Graphite theoretical capacity | 372 mAh/g | LiC₆ |
| Li metal capacity | 3861.88 mAh/g | Notes round to 4000 |

## 2. Electrochemistry fundamentals

| Quantity | Formula | Notes |
| --- | --- | --- |
| Charge | Q = i·t | Ah if i in A and t in h |
| Capacitive current | i = dq/dt = C·dV/dt | dV/dt = ν is the scan rate |
| Cell voltage | E\_cell = E\_cathode − E\_anode | Cathode is the more positive electrode |
| Free energy | ΔG = −nFE | E = −ΔG/(nF) |
| Capacitance unit | F = C²/J |  |
| Aqueous limit | H₂O → H₂ + ½O₂ at 1.23 V | Why Li-ion uses organic solvents |
| Fermi level | E\_F rises when e⁻ are added, falls when removed | Charging a cathode lowers E\_F and raises V |

**Key worked values**

- Li–S: E = 432000 / (2 × 96485) ≈ 2.24 V (ΔG = −432 kJ/mol, n = 2).
- LCO‖Li at 4 V: ΔG ≈ −386 kJ/mol. LCO‖graphite at 3.8 V: ΔG ≈ −367 kJ/mol.
- Lead-acid: E° ≈ 2.01 V.

## 3. Capacity, energy and specific energy

| Quantity | Formula | Example |
| --- | --- | --- |
| Energy | E (Wh) = V × Q (Ah) | 3.7 V × 3.4 Ah = 12.58 Wh |
| Specific energy (energy density) | Wh/kg = V\_nominal × capacity / battery weight | 3.6 V × 5 Ah / 0.090 kg = 200 Wh/kg |
| Series pack voltage | V\_pack = n\_series × V\_cell | 5 × 3.7 = 18.5 V |
| Parallel pack capacity | Q\_pack = n\_parallel × Q\_cell | 3 × 3.4 = 10.2 Ah |
| Pack energy | Wh = V\_pack × Q\_pack | 18.5 × 3.4 = 62.9 Wh (your Q1) |
| Practical capacity | Q = i·t\_cut-off / (3600 × m) | i in mA, t in s, m in g gives mAh/g |
| Material-level energy | Wh/kg ≈ V\_avg × Q\_practical (mAh/g) | NMC811: 3.8 × 205 ≈ 780 Wh/kg |
| Utilisation / Li fraction removed | x = Q\_practical / Q\_th | LCO: 137/274 = 0.5 |

**Unit check:** mAh/g is numerically the same as Ah/kg, so V × (mAh/g) gives Wh/kg directly.

## 4. Theoretical capacity

```latex
Q_{th}\ (\mathrm{mAh/g}) = \frac{nF}{3.6\,M} = \frac{n \times 96500}{3.6 \times M}
```

n is the number of electrons (Li) exchanged per formula unit written, and M is the molar mass of the formula unit that carries that n. For graphite, 1 e⁻ per 6 C gives n = 1/6 with M = 12.01. For Si → Li₁₅Si₄ use n = 15/4 with M = 28.09.

**Atomic masses used (g/mol)**

| Li | C | O | Al | Si | P | Ti | Mn | Fe | Co | Ni | Sn |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 6.94 | 12.01 | 16.00 | 26.98 | 28.09 | 30.97 | 47.87 | 54.94 | 55.85 | 58.93 | 58.69 | 118.71 |

**Worked values**

| Material | Reaction basis | M (g/mol) | n | Q\_th (mAh/g) |
| --- | --- | --- | --- | --- |
| LiCoO₂ | LiCoO₂ → CoO₂ | 97.87 | 1 | 274 (practical 137 at x = 0.5) |
| LiFePO₄ | → FePO₄ | 157.76 | 1 | 170 |
| LiMn₂O₄ | → λ-MnO₂ type | 180.82 | 1 | 148 |
| NMC111 | LiNi₁/₃Mn₁/₃Co₁/₃O₂ | 96.48 | 1 | 278 |
| NMC811 | LiNi₀.₈Mn₀.₁Co₀.₁O₂ | 97.28 | 1 | 275.5 |
| NMC622 | LiNi₀.₆Mn₀.₂Co₀.₂O₂ | 96.93 | 1 | 276.5 |
| NCA | LiNi₀.₈Co₀.₁₅Al₀.₀₅O₂ | 96.08 | 1 | 279 |
| LNMO | LiNi₀.₅Mn₁.₅O₄ | 182.70 | 1 | 146.7 |
| Graphite | Li + 6C → LiC₆ | 12.01 | 1/6 | 372 |
| Si | 15Li + 4Si → Li₁₅Si₄ | 28.09 | 15/4 | 3579 |
| Sn | Sn + 4.4Li → Li₄.₄Sn | 118.71 | 4.4 | 994 |
| Li₄Ti₅O₁₂ | → Li₇Ti₅O₁₂ | 459.1 | 3 | 175 |
| Li metal | Li → Li⁺ + e⁻ | 6.94 | 1 | 3861.88 |
| LiC₇₂ (stage 4) |  | 12.01 | 1/72 | 31 |

**Molar mass of a mixed formula (NMC style):** M = M\_Li + Σ(fraction × M\_TM) + M\_O. Example NMC811: 6.94 + 0.8(58.69) + 0.1(54.94) + 0.1(58.93) + 32 = 97.28.

**Graphite stages:** Q = 372/stage number, so stage 4 (LiC₇₂) ≈ 31, stage 3 (LiC₃₆) ≈ 62, stage 2 (LiC₁₂) ≈ 186, stage 1 (LiC₆) = 372 mAh/g.

**Sn caution:** your notes' 537.286 is the denominator 3.6 × 149.246. The usual answer uses the Sn mass (118.71), which gives 994 mAh/g. Using the lithiated alloy mass (149.246) gives ≈ 790 mAh/g. State which basis you use.

## 5. Alloy, mixed anode, composite and balancing formulas

| Quantity | Formula | Example |
| --- | --- | --- |
| Mixed or composite capacity | Q = Σ (weight fraction × Q\_th) | Si 0.6 / Sn 0.4: 0.6(3579) + 0.4(994) = 2545 mAh/g |
| Si/graphite composite | Q = f(3579) + (1 − f)(372) | 5/95: 532 mAh/g. 10/90: 692.7 mAh/g |
| Si capacity vs x in LiₓSi | Q ≈ 954 x mAh/g | x = 3.75: 3579. x = 4.4: ≈ 4200 |
| Sn capacity vs x in LiₓSn | Q ≈ 226 x mAh/g | x = 4.4: 994 |
| Anode mass for capacity balance | m\_anode = Q\_cathode,total / Q\_anode | 274 mAh / 3579 = 0.077 g Li₁₅Si₄ |
| Same with graphite | m = 274 / 372 | ≈ 0.73 g (total 1.73 g with 1 g LCO) |
| N/P ratio | (anode capacity) / (cathode capacity) | Typical 1.05–1.2 to avoid plating |
| Anode mass with N/P | m = N/P × Q\_cathode,total / Q\_anode,practical | 1.1 × 140 / 340 ≈ 0.45 g graphite per g LCO |
| Li needed for an alloy | m\_Li = x × (m\_host/M\_host) × 6.94 | 1 g Si, x = 3.75: 0.93 g Li |
| Mass gain on lithiation | Δm/m = x × 6.94 / M\_host | Si, x = 3.75: 93% |

**Mixing rule caution:** weights add capacities in mAh/g only if the fractions are weight fractions of active material. Binder and carbon dilute the result.

## 6. C-rate, current and time

| Quantity | Formula | Example |
| --- | --- | --- |
| C-rate definition | 1C = full capacity in 1 h; nC = full capacity in 1/n h | 2C = 0.5 h |
| Current | I = C-rate × Q × mass | Graphite 1 mg at 1C: 0.372 mA |
| Time | t (h) = 1 / C-rate | C/30 = 30 h |
| Cell current | I (A) = C-rate × Q\_cell (Ah) | 3.4 Ah cell at 2C: 6.8 A |
| Time to cut-off | t = Q / I | 2 mAh at 0.2 mA = 10 h |
| Capacity from a test | Q = I × t / m | 2 mA for 100 h on 0.5 g: 400 mAh/g |

**Your note's problem 2:** the result written is Q = 400 mAh/g. Because this is above the 274 mAh/g theoretical for LiCoO₂, the cell is overcharged (voltage limit exceeded). Whatever the exact inputs, always compare the computed capacity with Q\_th.

**Trends to state in answers:** a higher C-rate gives a larger IR drop, a lower discharge voltage, shorter discharge time and less delivered capacity, because side products raise R. At very high charge C-rate on graphite, Li⁺ cannot diffuse in time, so plating and dendrites follow.

## 7. Efficiency, fade and losses

| Quantity | Formula | Example |
| --- | --- | --- |
| Coulombic efficiency | CE = Q\_discharge / Q\_charge × 100% | 140/150 = 93.3% |
| Irreversible loss | Q\_irr = Q\_charge − Q\_discharge | 10 mAh |
| First-cycle efficiency | Q\_out / Q\_in of cycle 1 | Si slide: 2700/3600 = 75% |
| Capacity retention | Q\_n / Q\_1 × 100% |  |
| Retention from CE | ≈ CEⁿ | 0.999¹⁰⁰ ≈ 90%; 0.995¹⁰⁰ ≈ 61%; 0.99¹⁰⁰ ≈ 37% |
| Li lost in a cycle | n\_Li = Q\_irr (mAh) × 3.6 / 96500 | 10 mAh: 3.7 × 10⁻⁴ mol |
| Joule heating | P = I²R | Rises with C-rate and with side-product resistance |
| Voltage hysteresis | ΔV = V\_charge − V\_discharge at the same SOC | Due to IR and polarisation |

## 8. Cell and pack formulas

| Quantity | Formula | Example |
| --- | --- | --- |
| Series | V = n × V\_cell, capacity unchanged | 5 cells of 3.7 V: 18.5 V |
| Parallel | Q = n × Q\_cell, voltage unchanged | 3 cells of 3.4 Ah: 10.2 Ah |
| Energy | Wh = V × Ah | 18.5 × 3.4 = 62.9 Wh |
| Mixed pack (s × p) | Wh = (s × V\_cell) × (p × Q\_cell) | 4s2p of 3.6 V, 5 Ah: 14.4 V × 10 Ah = 144 Wh |
| Electrode composition | active 85% + carbon 10% + binder 5% | Scale to the active mass for mAh/g |
| Full-cell voltage | V = E\_cat − E\_an | LCO‖graphite ≈ 3.8 V |

## 9. XRD and crystallography formulas

```latex
n\lambda = 2d\sin\theta \qquad d = \frac{\lambda}{2\sin\theta} \qquad 2\theta = 2\arcsin\!\left(\frac{\lambda}{2d}\right)
```

| Quantity | Formula | Example |
| --- | --- | --- |
| Bragg's law | nλ = 2d sinθ | λ = 1.54056 Å |
| d from peak | d = λ / (2 sin(2θ/2)) | LCO (003) at 2θ = 18.80°: 4.72 Å |
| c lattice parameter (layered O₃) | c = 3 d(003) | 3 × 4.72 = 14.16 Å |
| Stage 2 spacing | d(002) ≈ 3.5 Å (LiC₁₂) | 2θ ≈ 25.4° |
| Stage 1 spacing | d(001) ≈ 3.7 Å (LiC₆) | 2θ ≈ 24.0° |
| Graphite (002) | d ≈ 3.354 Å | 2θ ≈ 26.6° |
| Percent change in d | (d₂ − d₁)/d₁ × 100 | 4.741 → 4.897 Å: 3.3% |
| Peak shift rule | Lower 2θ means larger d | (003) shifts left as Li leaves, c grows |
| Stacking notation | ABCABC → O₃, ABBCCA → P₃, ABBA → P₂, ABAC → O₂ |  |

**Order of steps:** convert 2θ to θ first (halve it), take sin, then divide. Using 2θ in the sine is the most common error.

## 10. Kinetics, diffusion and temperature

```latex
t \approx \frac{L^2}{D} \qquad k = A\,e^{-E_a/RT} \qquad \frac{k_2}{k_1} = \exp\!\left[\frac{E_a}{R}\left(\frac{1}{T_1}-\frac{1}{T_2}\right)\right]
```

| Quantity | Formula | Example |
| --- | --- | --- |
| Diffusion time | t ≈ L²/D | L = 10 µm, D = 10⁻¹⁰ cm²/s: 10⁴ s ≈ 2.8 h |
| Effect of size | t scales with L² | 10× smaller gives 100× faster |
| Arrhenius ratio | k₂/k₁ as above | E\_a = 50 kJ/mol, 25 → 45 °C: ≈ 3.5× |
| Temperature trend | T up: faster kinetics, higher ionic conductivity, lower electronic conductivity | Balance ionic and electronic transport |

D ≈ 10⁻¹⁰ cm²/s is an assumed typical value, so use the number your question gives.

## 11. Numerical problem scope

These are the problem types your notes and slides support, with the method for each.

| # | Problem type | Method | Check |
| --- | --- | --- | --- |
| 1 | Pack voltage, capacity, energy | Series adds V, parallel adds Ah, Wh = V × Ah | 5 × 3.7 V, 3.4 Ah: 62.9 Wh |
| 2 | Specific energy | Wh/kg = V × Ah / kg | Convert g to kg |
| 3 | Theoretical capacity from formula | Find M, choose n, apply nF/(3.6 M) | Result is near 270–280 for layered oxides |
| 4 | Fraction of Li extracted | x = Q\_practical / Q\_th | LCO is about 0.5 |
| 5 | Capacity of mixed or alloy anode | Weighted sum of Q\_th by weight fraction | 2545 and 532 mAh/g |
| 6 | Capacity of LiₓM alloy | Q = x·F/(3.6 M\_host) | Si x = 3.75 gives 3579 |
| 7 | Anode mass to balance a cathode | m = Q\_cathode / Q\_anode | 0.077 g Si alloy vs 0.73 g graphite per 274 mAh |
| 8 | C-rate current | I = C × Q × m | 372 mA for 1 g graphite at 1C |
| 9 | Discharge time at a given C | t = 1/C | 2C is 0.5 h |
| 10 | Overcharge detection | Compare computed Q with Q\_th | 400 > 274 means overcharged |
| 11 | Coulombic efficiency and Li loss | CE = Q\_d/Q\_c; n = Q × 3.6/96500 | 93.3% |
| 12 | Bragg: d from 2θ | Halve 2θ, then d = λ/(2 sinθ) | 18.80°: 4.72 Å |
| 13 | c parameter and percent change | c = 3d(003); % = Δd/d₁ | 3.3% for 4.741 to 4.897 Å |
| 14 | Peak position from d | 2θ = 2 arcsin(λ/2d) | Graphite 26.6°, LiC₆ 24.0° |
| 15 | Free energy ↔ voltage | ΔG = −nFE | Li–S 2.24 V |
| 16 | Graphite stage capacity | 372 / stage number | 31, 62, 186, 372 |
| 17 | Diffusion and Arrhenius estimates | t = L²/D; rate ratio | 2.8 h; 3.5× |

**Common pitfalls**

- Use λ in Å and get d in Å. Your notes wrote λ in degrees.
- Halve 2θ before taking the sine.
- Pick M and n on the same basis (n = 1 with M of LiCoO₂, not CoO₂ unless stated).
- For graphite, n = 1/6 with M = 12.01, which is the same as n = 1 with M = 6 × 12.01.
- State the mass basis for alloys (host mass gives 994 for Sn; alloy mass gives about 790).
- mAh/g needs mA and h (or divide by 3600 if the time is in s).
- Check the answer against the theoretical limit before trusting it.
- A percent change is relative to the starting value (3.3%, not 2.64%).

## 12. Results table of computed numbers

| Item | Value |
| --- | --- |
| Pack: 5 × 3.7 V, 3.4 Ah | 18.5 V, 62.9 Wh |
| Specific energy example (3.6 V, 5 Ah, 90 g) | 200 Wh/kg |
| LiCoO₂ Q\_th / practical | 274 / 137 mAh/g (x = 0.5) |
| LiFePO₄ | 170 mAh/g |
| LiMn₂O₄ | 148 mAh/g |
| NMC111 / 622 / 811 | 278 / 276.5 / 275.5 mAh/g |
| NCA | 279 mAh/g |
| LNMO | 146.7 mAh/g |
| Li₄Ti₅O₁₂ | 175 mAh/g |
| Graphite | 372 mAh/g |
| Graphite stages 4, 3, 2, 1 | 31, 62, 186, 372 mAh/g |
| Si (Li₁₅Si₄) | 3579 mAh/g |
| Sn (Li₄.₄Sn), host mass | 994 mAh/g |
| Sn, alloy mass basis | ≈ 790 mAh/g |
| Li metal | 3861.88 mAh/g |
| Si 0.6 / Sn 0.4 | 2545 mAh/g |
| Si 0.05 / graphite 0.95 | 532 mAh/g |
| Si 0.10 / graphite 0.90 | 692.7 mAh/g |
| Anode mass per 274 mAh | 0.077 g Li₁₅Si₄ vs 0.73 g graphite |
| Total mass with 1 g LCO | 1.07 g (Si) vs 1.73 g (graphite) |
| 1 g graphite at 1C | 372 mA |
| LCO (003) at 2θ = 18.80° | d = 4.72 Å, c = 14.16 Å |
| Peak shift 4.741 → 4.897 Å | +3.3% |
| Li–S voltage | 2.24 V |
| LCO‖Li / LCO‖graphite ΔG | −386 / −367 kJ/mol |
| CE example 140/150 | 93.3% |
| Retention after 100 cycles at CE 99.9% / 99.5% / 99% | 90% / 61% / 37% |
| Diffusion time, L = 10 µm, D = 10⁻¹⁰ cm²/s | ≈ 2.8 h |
| Arrhenius, E\_a = 50 kJ/mol, 25 → 45 °C | ≈ 3.5× |
