# CY4050 Battery Materials Notes

Oct 10, 2026 · @Balasathya

## 1. Basics and measurements

These notes are compiled from your handwritten notes and the graphite/Si anode slides. Likely errors in your notes are marked ⚠️ with the corrected value; items I added that are not in your notes are marked (added).

**Three-electrode cell:** WE (working), RE (reference) and CE (counter). The WE has Ox + e⁻ → Red and the CE has Red → Ox + e⁻. The reference electrode sets the potential and carries no current.

**What we can measure:** current (A), potential (V), concentration, capacity Q (Ah), capacitance (F = C²/J).

**Core formulas**

- Q = i·t (Ah)
- i = dq/dt = C·dV/dt, where dV/dt = ν is the scan rate
- Energy density (specific energy, Wh/kg) = nominal voltage × capacity / battery weight
- E\_cell = E\_cathode − E\_anode (this is why different materials give different voltages)
- E = −ΔG / nF (added; this is how the Li–S value below works)

**Current collectors.** Your notes pose two questions: why Al is the cathode collector in Na-ion batteries (SIB), and why Cu is the anode collector in Li-ion batteries (LIB). Likely answers (added):

- Cu is stable at low potential and does not alloy with Li. Al alloys with Li at low potential, so it can't be used on a LIB anode.
- Al does not alloy with Na, so it works in SIBs. It is cheap and light, and a passive oxide/fluoride film protects it at high potential.
- Cu dissolves at high potential, so it can't be used on cathodes.

**Electrode fabrication:** make a slurry of active material (85%) + conducting carbon (10%) + binder (5%); the ratios can be changed. Coat it on the current collector, then stamp/cut to size. The electrode is made.

**Worked problems (as written in your notes)**

- Q1: 3.7 V × 5 = 18.5 V, capacity 3400 mAh, energy = 18.5 × 3.4 = **62.9 Wh**
- Q2 answers: 4, 3, 12 and **150.96 Wh**

## 2. Battery types

Batteries are classified by the phase of the electrode / electrolyte / electrode, and by material.

| Classification | Type | Example |
| --- | --- | --- |
| By phase (electrode / electrolyte / electrode) | Solid–Liquid–Solid | Li-ion, lead-acid |
|  | Liquid–Solid–Liquid | Na–S |
|  | Solid–Solid–Solid | All-solid-state |
| By material | Electrodes: metal/alloy, ceramic, polymer |  |
|  | Liquid electrodes: melt, metal ions, organic compounds |  |
|  | Gas electrode: O₂ |  |
|  | Electrolyte: solution |  |

## 3. Voltage profiles

- **Zn|Cu cell:** measure the open-circuit potential (V\_OCP), then apply a constant current. V rises during charging because concentrations change. This is charging in **CC (constant-current) mode**.
- **Li-ion style profile (3 V → 3.6 V):** V rises steeply at low SOC, follows a long flat plateau, then rises sharply to the cut-off at 100% SOC.
- **Electron transfer gives the voltage profile**, and from it we get E\_anode and E\_cathode.

**Fermi level picture**

- Adding electrons raises E\_F. Removing electrons lowers E\_F.
- At equilibrium the electrode and solution Fermi levels match ("Fermi's match"). Electrons then transfer between the electrode and the redox species in solution.

## 4. LiCoO₂ (LCO) in detail

**Oxidation states:** Li⁺¹, Co⁺³, O⁻². Co (Z = 27) is 1s² 2s² 2p⁶ 3s² 3p⁶ 4s² 3d⁷. Co³⁺ is 3d⁶, with t₂g fully filled and e\_g empty.

**Charging reaction.** The Co oxidation state goes from +3 to +(3+x), the Fermi level drops and the potential rises.

```latex
\mathrm{LiCoO_2} \rightarrow \mathrm{Li_{1-x}CoO_2} + x\,\mathrm{Li^+} + x\,e^-
```

**Voltage profile:** the cathode goes from 2.5 V up to 4.2 V on charge. Charging is stopped manually at 4.2 V, then discharge follows.

**Why only partial charging (about 50% Li extraction)?**

- The structure is layers of TMO₆ with Li between them.
- When Li⁺ leaves, the oxide–oxide layers repel each other, so **c increases** (elongation) and the cell can become tetragonal.
- With about 50% Li left, the layers can still slide and the structure holds.
- So only 50% of the Li in LiCoO₂ is extracted (x = 0.5).

**Molecular orbital view of LiMO₂ (octahedral)**

- Metal orbitals: nd (t₂g, e\_g), (n+1)s, (n+1)p. Oxygen orbitals: 2pσ, 2pπ.
- Bonding MOs are a₁g, t₁u and e\_g. The non-bonding set is t₂g (metal) and O\_NB (non-bonding oxygen). The antibonding MOs lie above.
- All of these together form bands. The DOS plot shows the Fermi level inside the metal t₂g/e\_g band.
- **Overcharging:** E\_F drops as you charge. After a point it reaches the O non-bonding band (O 2p), so as V rises the **Co–O bond breaks and O₂ gas is released**. This is the origin of safety and structural problems at high voltage.

## 5. Substitution: NMC, NCA and solid solutions

**Replace Co with Ni and Mn.** Li(Ni)ₓ(Mn)ᵧ(Co)\_zO₂ forms a **solid solution**, and diffusion can happen in a solid solution.

**Oxidation states:** Li⁺¹, Ni⁺², Mn⁺⁴, Co⁺³, O⁻². Average TM = +3.

**Conditions for forming a solid solution (Hume-Rothery type rules)**

1. Atomic size differs by no more than 15%.
2. Solute and solvent have the same crystal structure.
3. No large electronegativity difference.
4. Same valency. Exception: a metal is more likely to dissolve a metal of higher valency than the reverse.

- **Substitutional alloy:** atom A is replaced with B.
- **Interstitial alloy:** the atom sits in an interstitial site.

**Electronic effects**

- Mn³⁺ is Jahn–Teller active, so it goes to Mn⁴⁺ for stability.
- Ni²⁺ has 2 e⁻ in e\_g and can give up 2 e⁻ (→ Ni⁴⁺), so **more charge** can be extracted.

**Compositions**

| Name | Formula |
| --- | --- |
| NMC811 | LiNi₀.₈Mn₀.₁Co₀.₁O₂ |
| NMC111 | LiNi₀.₃₃Mn₀.₃₃Co₀.₃₃O₂ |
| NMC622 | LiNi₀.₆Mn₀.₂Co₀.₂O₂ |

- Co is expensive and toxic, so we reduce it. This is a **cost vs capacity/voltage trade-off**, adjusted by the stoichiometric ratio.
- Related end members: LiFeO₂, LiNiO₂, LiMnO₂ (Mn³⁺, 3d⁴, Jahn–Teller).
- **NMCA / NCA:** Al is +3. Whether it sits on the Li site or the TM site is unknown.

**Halogen doping:** O²⁻ can be partly replaced by F⁻.

- Less Li is needed to compensate, so Li intercalates and deintercalates more easily.
- Kinetics are much faster, which gives high C-rate capability.

**Cathode window:** about 2.5–4 V.

## 6. Cycling behaviour

- **Galvanostatic charge/discharge (GCD):** apply a constant current and measure the potential. Example: 65 µA, with a cut-off at 4.2 V.
- The Galvani potential differences at the two interfaces are Δφ₁ = φᴹ¹ − φˢ and Δφ₂ = φᴹ² − φˢ.
- The charge and discharge curves are separated by potential (IR) drops.
- Plotting V against capacity gives Li extraction/insertion for the cathode, and "Li entering" (to LiC₆) for graphite.

**Coulombic loss:** charge 150 mAh, discharge 140 mAh (CE ≈ 93%). The missing fraction of Li⁺ goes into side reactions, which form a resistive layer and cause Joule heating.

**Capacity fade:** discharge curves at 10, 50 and 100 cycles show falling capacity and worse performance. You can also plot discharge capacity vs cycle number.

**Why the choice of cathode?**

- The voltage ordering is NMC > LiMn₂O₄ > LiCoO₂ > LiFePO₄. Higher-voltage cathodes break down the **organic solvent**.
- **Why not aqueous electrolyte?** H₂O → H₂ + ½O₂ at **1.23 V**. So we would need lower potentials, which means lower energy density.
- Gaining capacity by raising the voltage cut-off comes at the cost of unstable cycle life.

**Cathode families**

| Name | Formula |
| --- | --- |
| LCO | LiCoO₂ |
| NCA | LiNi₀.₈Co₀.₁₅Al₀.₀₅O₂ |
| NMC | LiNi₁₋ₓ₋ᵧMnₓCoᵧO₂ |
| LMO | LiMn₂O₄ |
| LFP | LiFePO₄ (⚠️ the notes write LiFePO₂) |

**Why such a variation in voltage?** It comes from the Fermi level position as you go from d¹ to d⁶. Voltage = electronic energy + M–O covalency + …

- LiCoO₂ ‖ Li: 4 V (the Co⁴⁺/Co³⁺ level is about 4 eV below Li⁺/Li).
- LiCoO₂ ‖ LiₓC₆: 3.8 V. Graphite sits about 0.2 eV below Li⁺/Li, so this is a small loss. It is used because Li metal is expensive and unsafe.

## 7. Anodes

A good anode has low V and high capacity.

| Material | Capacity / potential | Notes |
| --- | --- | --- |
| Graphite | 372 mAh/g | Intercalation, \~0.01–0.2 V |
| Li metal | \~3862 mAh/g (notes round to 4000) | Reacts with the electrolyte |
| Graphene | ≈ 600 mAh/g | Single sheet of graphite |
| Si/Sn oxides | E° = 0.5–1 V, ≈ 2000 mAh/g | Semiconductors, so electron transfer is poor |
| TiO₂ | E° = 1.5 V | Still used as an anode |

**Dimensionality:** graphene = 2D (electrons confined in 2 dimensions), graphite = 3D, carbon nanotubes = 1D, quantum dots = 0D.

**Which cell is preferred?** Of the sketched profiles, the one whose potential is flat over the whole capacity is preferred. Sloping or stepped profiles are bad because the average potential is hard to define and the voltage varies.

**Carbon allotropes (slide):** amorphous carbon/coal, graphite, graphene, diamond, lonsdaleite, fullerenes (C₆₀) and carbon nanotubes (SWCNT 0.5–2.5 nm, MWCNT 7–100 nm).

## 8. Other chemistries

**Lead–acid**

- (−): Pb(s) + HSO₄⁻ → PbSO₄(s) + H⁺ + 2e⁻
- (+): PbO₂(s) + HSO₄⁻ + 3H⁺ + 2e⁻ → PbSO₄ + 2H₂O
- E° ≈ 2.01 V

**Li–S**

- (−): 2Li → 2Li⁺ + 2e⁻
- (+): ⅛S₈ + 2Li⁺ + 2e⁻ → Li₂S
- ΔG = −432 kJ/mol, so E = 432000 / (2 × 96485) ≈ **2.24 V**

## 9. Theoretical capacity

Theoretical capacity in mAh/g, with F = 96500 C/mol and M in g/mol:

```latex
Q_{th} = \frac{nF}{3.6\,M}
```

| Material | Working | Result |
| --- | --- | --- |
| LiCoO₂ | M = 6.94 + 58.93 + 32 = 97.87; n = 1 | **274 mAh/g**. Only 0.5 Li is drawn, so **137 mAh/g** practical |
| LiFePO₄ | M = 157.76 | **170 mAh/g** |
| NMC111 | M = 96.48, n = 1 | **278 mAh/g** (practical 165 at C/30) |
| NMC811 | M = 6.94 + 0.8(58.69) + 0.1(54.94) + 0.1(58.93) + 32 = 97.28 | **275.5 mAh/g** |
| Graphite | 1 e⁻ per 6 C, so n = 1/6, M = 12.01 | **≈ 372 mAh/g** |
| Si | 15Li + 4Si → Li₁₅Si₄, n = 15/4 | **3579 mAh/g** |
| Sn | Sn + 4.4Li → Li₄.₄Sn | **994 mAh/g** (see ⚠️ below) |
| Li metal | Li → Li⁺ + e⁻ | **3861.88 mAh/g** |
| LiC₇₂ | (1/72)(96500) / (12.01 × 3.6) | **31 mAh/g** |

**Practical capacity** = i × t\_cut-off / (3600 × mass), with the mass in g and i in mA to get mAh/g.

**Mixed anodes (weighted average)**

- Si 0.6 / Sn 0.4: 0.6(3579) + 0.4(994) = **2545 mAh/g**
- Si 0.05 / graphite 0.95: ≈ **532 mAh/g**

⚠️ **Sn error in your notes.** You wrote 537.286, but that number is only the denominator 3.6 × 149.246. Dividing gives 4.4 × 96500 / 537.286 ≈ **790 mAh/g**, which uses the mass of the lithiated alloy (M = 4.4 × 6.94 + 118.71 = 149.246). The usual 994 mAh/g uses the mass of Sn (118.71), consistent with how Si's 3579 is calculated. Your Si/Sn mix calculation correctly uses 994.

**Capacity balancing** (anode mass needed to match 274 mAh of LiCoO₂)

- 1 g LiCoO₂ + \~0.07 g Li₁₅Si₄ ≈ **1.07 g**, so higher energy density.
- 1 g LiCoO₂ + 0.73 g graphite = **1.73 g**.
- The goal is that nearly everything reacts, with no wasted excess mass.
- A high-capacity anode is thinner, which cuts volume and mass and gives shorter diffusion paths and **faster charging**. A thick graphite electrode takes time to charge fully.

## 10. C-rate and temperature

- 1C = full capacity in 1 h; 2C = full capacity in 0.5 h.

```latex
I = C_{rate} \times Q_{th} \times \mathrm{mass}
```

- Example for graphite: 1 mg gives I = C × 0.372 mAh. At 1C, I = 0.372 mA; for 1 g at 1C, I = 372 mA.
- At higher C-rate the voltage drops and the discharge time falls.
  - Reason 1: unwanted side products form, so R rises.
  - Reason 2: with a faster C-rate there is less energy in the cell.

**Temperature**

- Higher T gives faster kinetics and higher ionic conductivity (faster diffusion).
- Higher T also lowers electronic conductivity, so resistance rises. The ionic and electronic contributions need to be balanced.
- Discharge curves shift with T. Low T gives a lower plateau and capacity.

## 11. Crystal structure and XRD

**Layered oxide notation (LiₓMnO₂ example)**

- **P-type:** Li in prismatic sites. **O-type:** Li in octahedral sites. There are also hybrids.
- The number (P₁, P₂, P₃, O₁, O₂, O₃) is how many times the stacking layers repeat.
- A and B layers are TM–O layers with Li between them.
- Stacking sequences: **ABCABC → O₃**, **ABBCCA → P₃**, **ABBA → P₂**, **ABAC → O₂**.

**Bragg's law and spacing**

```latex
n\lambda = 2d\sin\theta \qquad d = \frac{\lambda}{2\sin\theta}
```

For LiCoO₂ the (003) spacing is d = c/3 (about 4.67 Å).

**Problems from your notes**

1. x = 0.5 (Q\_th = 274, Q\_ex = 137), so 0.5 Li is left in LiCoO₂.
2. 2 mA at 200 /g gives Q = 400 mAh/g. This is far above the 274 mAh/g theoretical, so the cell is being overcharged (above the voltage limit).
3. (003) peak at 2θ = 18.80°, λ = 1.54056 Å (the notes write ° for the unit). d = λ/(2 sinθ) = **4.72 Å**.
4. c = 3d. ⚠️ 3 × 4.72 = **14.16 Å**. Your notes give 14.3, so check which d you used.
5. The peak shifts 18.70° → 18.10°.
   - i) d goes from 4.741 Å to 4.897 Å.
   - ii) ⚠️ (4.897 − 4.741)/4.741 = **3.3%**, not 2.64%.
   - iii) c has increased, and the structure goes from O₃ to O₃′.

**In-situ XRD during charging**

- As you charge, the (003) peak shifts to lower 2θ (c increases) and the (101) peak shifts the other way (a decreases).
- After full discharge, the pattern does not overlap with the pristine one, so the structure changes with cycling.
- Discharging brings repulsion between the MnO₆ layers (A and B), which leads to **stacking faults**.
- Fully charged means maximum repulsion and complete extraction, which causes structural change.
- **Co₃O₄** is irreversible and doesn't take part in charge/discharge: LiCoO₂ → Co₃O₄ + Li⁺ + e⁻.
- You start from O₃, but **P₃ is preferred** because Li⁺ can be extracted more easily. During Li extraction, P₃ → O₃ in the 002 plane: **c increases and a decreases**.
- The cause is oxide–oxide repulsion along c, while M–O contraction shrinks a and b.
- Pushing the voltage beyond the cutoff gives extra capacity but damages the structure.

## 12. Graphite anode: details

**Mechanism**

- Graphite (3D) stores Li⁺ through **intercalation** into graphitic intercalation compounds (GIC): Li + 6C ⇌ LiC₆, with Q = 372 mAh/g.
- Solvated Li⁺ (surrounded by solvent molecules) approaches the graphite and enters between the layers. Interlayer distance is 0.3354 nm and the C–C bond is 0.142 nm.
- LiPF₆ in EC:DMC works, but NaPF₆ does not (Na doesn't intercalate into graphite).
- Average voltage is about 0.2 → 0.01 V vs Li.

**Two competing reactions**

- Li⁺ + e⁻ + 6C → LiC₆ at 0.01 V (desired).
- Li⁺ + e⁻ → Li at 0.0 V (plating).
- So we only go down to **0.01 V**; the cut-off is at 0.01 V. Going lower gives Li dendrites and **short circuit**.
- **Dendrites** form when Li⁺ deposits on the graphite surface instead of inside it. This happens at high C-rate and high current: Li⁺ cannot diffuse in time, so capacity falls, voltage is lost, and then dendrites form.
- Other carbons (graphene, fullerenes) can't be expected to give LiC₆.

**Staging (voltage plateaus)**

| Stage | Composition | Notes |
| --- | --- | --- |
| 4 | LiC₇₂ | ≈ 30–40 mAh/g (calculated 31) |
| 3 | LiC₃₆ | (added) calculated ≈ 62 mAh/g |
| 2 | LiC₁₂ | (added) calculated ≈ 186 mAh/g |
| 1 | LiC₆ | 372 mAh/g; golden colour |

- Plateaus in the slides sit around 0.2, 0.12 and 0.09 V. Lower rates (1/10C, 1/100C, 1/250C) give more capacity and sharper plateaus.
- ⚠️ Your sketch marks "250" near the LiC₁₂ step. The theoretical capacity at stage 2 is about 186, so check what 250 refers to.
- Slide labels also show stages 1L, 2L, 3 and 4 (L = liquid-like or dilute lattice).

**XRD of graphite lithiation**

- As Li is added, the 002 plane shifts to a larger d spacing and fully disappears. The 001 plane appears while charging.
- **002 → LiC₁₂** (d ≈ 3.5 Å), **001 → LiC₆** (d ≈ 3.7 Å). Graphite itself has d(002) ≈ 3.35 Å, 2θ ≈ 26.5°.
- LiC₁₂ appears at around 25.2° and LiC₆ at around 24°.
- In-situ XRD over 3 cycles shows these peaks appearing and disappearing reversibly.

**Volume change (in-situ dilatometry):** the graphite electrode swells on lithiation and shrinks on delithiation, tracked as thickness change in 1M LiPF₆ in EC:DMC. Poor volume control leads to swelling and failure. The slide shows a bloated and a burnt phone battery.

## 13. Silicon and tin anodes

**Mechanism:** alloy formation, not intercalation. Si stores Li by forming Li–Si intermetallic compounds.

**Li–Si phase diagram (slides)**

- Compounds: Li₂₂Si₅, Li₁₃Si₄, Li₇Si₃, Li₁₂Si₇ and LiSi. Melting points: Li 180.6 °C, Si 1414 °C.
- At 450 °C, lithiation and delithiation give stepwise plateaus (two-phase regions):
  - Si + Li₁₂Si₇
  - Li₁₂Si₇ + Li₁₄Si₆ (x = 1.71)
  - Li₁₄Si₆ + Li₁₃Si₄ (x = 2.33)
  - Li₁₃Si₄ + Li₂₂Si₅ (x = 3.25)
  - up to x = 4.4
- At room temperature the curve is smooth and sloping (lithiation near 0.1 V, delithiation around 0.3–0.5 V). Room-temperature lithiation forms amorphous phases.
- Slide capacity: first cycle ≈ 3600 mAh/g in and ≈ 2700 out, then ≈ 2400 on the second cycle, so there is irreversible loss.
- A Li–Sn phase diagram is also shown (LiSn, Li₂Sn₅-type and Li₂₂Sn₅/Li₇Sn₂ compounds).

**Problems with Si**

- Increasing the Si fraction lowers conduction and increases **volume**, which causes **pulverization**: particles crack, lose contact with the current collector, and SEI keeps re-forming. The result is **capacity fading**.
- Sn has the same issue: Sn → Li₄.₄Sn → fragmented Sn particles.
- ⚠️ Your pulverization sketch labels Na⁺ for Si; it should be Li⁺ (the slide image comes from a Na–Sn example).

**Binder effect (slide):** charge–discharge between 0.01 and 1 V at 4200 mA/g.

| Binder | Behaviour over cycling |
| --- | --- |
| Alginate | Keeps ≈ 1700–2000 mAh/g over 100 cycles |
| CMC | Fades to about 800 mAh/g within about 45 cycles |
| PVDF | Fades to near the graphite theoretical value (\~370 mAh/g) |

A better binder improves cycle life by holding the cracked Si together.

**Mitigation:** a Si/graphite composite (e.g. 5/95) gives ≈ 532 mAh/g while limiting expansion. Nano-structuring also helps.

## 14. Quick formula sheet

| Quantity | Formula |
| --- | --- |
| Charge | Q = i·t |
| Capacitive current | i = C·dV/dt |
| Cell voltage | E\_cell = E\_cat − E\_an |
| Free energy | ΔG = −nFE |
| Energy density | V\_nominal × capacity / mass |
| Theoretical capacity | Q\_th = nF/(3.6 M) mAh/g |
| Practical capacity | i·t\_cutoff / (3600·m) |
| Applied current | I = C-rate × Q\_th × mass |
| Bragg's law | nλ = 2d sinθ |
| Interplanar spacing | d = λ / (2 sinθ); c = 3d for (003) |
| Mixed anode | Q = Σ (fraction × Q\_th) |
| Cell pack | V = n\_series × V\_cell; Wh = V × Ah |

## 15. Likely exam questions

1. Why does LiCoO₂ only give about 137 mAh/g? Only about 50% of the Li can be extracted; layer collapse and O loss occur beyond that.
2. Why is the graphite cut-off 0.01 V and not 0 V? It avoids Li plating and dendrites.
3. Why do Si anodes fade? Volume expansion, pulverization, loss of contact and repeated SEI formation.
4. Why can't an aqueous electrolyte be used for high-energy Li-ion? Water splits at 1.23 V.
5. State the Hume-Rothery rules for a solid solution, and explain why NMC forms one.
6. Explain O₃ vs P₃ stacking, and how XRD shows structural change.
7. Why does a high C-rate lower capacity and voltage?

# Part B: Extended data and worked examples (added)

Everything in Part B is extrapolated from your notes and slides using standard values. Literature values are approximate and vary by paper, so treat them as typical ranges and check them against your course material before quoting them.

## 16. Cathode comparison with extrapolated data

Theoretical capacity uses Q\_th = nF/(3.6 M) with n = 1. Utilisation = practical ÷ theoretical, which is the fraction x of Li actually cycled. Approximate material-level energy = average voltage × practical capacity.

| Cathode | M (g/mol) | Q\_th (mAh/g) | Practical (mAh/g) | Utilisation | Avg V vs Li | Energy (Wh/kg, approx) |
| --- | --- | --- | --- | --- | --- | --- |
| LCO (LiCoO₂) | 97.87 | 274 | 140–150 | ≈ 53% | 3.9 | ≈ 565 |
| NMC111 | 96.48 | 278 | 160–170 | ≈ 59% | 3.8 | ≈ 625 |
| NMC622 | 96.93 | 276.5 | 175–185 | ≈ 65% | 3.8 | ≈ 685 |
| NMC811 | 97.28 | 275.5 | 200–210 | ≈ 74% | 3.8 | ≈ 780 |
| NCA | 96.08 | 279 | 195–200 | ≈ 70% | 3.8 | ≈ 750 |
| LMO (LiMn₂O₄) | 180.82 | 148 | 100–120 | ≈ 74% | 4.0 | ≈ 440 |
| LFP (LiFePO₄) | 157.76 | 170 | 150–160 | ≈ 91% | 3.45 | ≈ 535 |

**What the table shows**

- Theoretical capacity is almost the same (274–279 mAh/g) for all the layered oxides, because their molar masses are almost the same. The difference in practical capacity comes from how much Li can be removed before the structure fails.
- LCO gives up only about half its Li (x ≈ 0.5), as in your notes. Ni-rich NMC and NCA give up about 0.7, which is why Ni content raises capacity.
- LFP uses almost all of its Li because the olivine framework barely changes volume (about 6.5%), but its low voltage (3.45 V) and low electronic conductivity limit energy.
- LMO has a low Q\_th because Mn₂O₄ is heavy per Li, and it suffers Mn dissolution (Jahn–Teller Mn³⁺ disproportionation).

**Calculation check for LMO:** M = 6.94 + 2(54.94) + 4(16.00) = 180.82 g/mol, so Q\_th = 96500 / (3.6 × 180.82) = **148 mAh/g**.

**Cathode families by structure**

| Structure | Examples | Li path | Key weakness |
| --- | --- | --- | --- |
| Layered (2D diffusion) | LCO, NMC, NCA | Between TMO₆ layers | O loss and phase change at high V |
| Spinel (3D diffusion) | LMO | Through tetrahedral sites | Mn dissolution |
| Olivine (1D diffusion) | LFP | Along the b-axis channel | Low conductivity, 1D channels block easily |

## 17. Anode comparison with extrapolated data

For an alloy LiₓM, the capacity per gram of host is Q = x·F/(3.6·M\_host). This gives a handy linear rule.

```latex
Q_{Si}(x) = x \cdot \frac{96500}{3.6 \times 28.09} \approx 954\,x \ \text{mAh/g} \qquad Q_{Sn}(x) = x \cdot \frac{96500}{3.6 \times 118.71} \approx 226\,x \ \text{mAh/g}
```

- Si: x = 3.75 (Li₁₅Si₄) gives 3579 mAh/g, and x = 4.4 (Li₂₂Si₅) gives about 4200 mAh/g. The slide's "4200" is this fully lithiated limit.
- Sn: x = 4.4 gives **994 mAh/g**, which confirms the Sn mass is the right basis.
- Graphite: x = 1 per 6 C gives 372 mAh/g.

| Anode | Mechanism | Capacity (mAh/g) | Potential vs Li | Volume change | First-cycle efficiency | Main issue |
| --- | --- | --- | --- | --- | --- | --- |
| Graphite | Intercalation | 372 | 0.01–0.2 V | ≈ 10–13% | ≈ 90–95% | Plating at high C-rate |
| Hard carbon | Insertion and pore filling | ≈ 250–300 | 0–1 V, sloping | small | ≈ 70–85% | Low efficiency |
| Li₄Ti₅O₁₂ (LTO) | Insertion, zero strain | 175 | ≈ 1.55 V flat | ≈ 0.2% | ≈ 95%+ | Low voltage window means low energy |
| Si | Alloy | 3579 (to 4200) | 0.1–0.4 V | ≈ 280–300% | ≈ 75–85% (slide ≈ 75%) | Pulverization, SEI |
| Sn | Alloy | 994 | 0.4–0.8 V | ≈ 250–260% | ≈ 70–80% | Pulverization |
| Li metal | Plating/stripping | 3862 | 0 V | large | n/a | Dendrites, reactivity |

**Reading the slide numbers:** the Si first cycle shows roughly 3600 mAh/g in and 2700 mAh/g out, so first-cycle efficiency ≈ 2700/3600 = **75%**. The lost 900 mAh/g is trapped Li and SEI. The second cycle is about 2400 mAh/g out.

**Why LTO is safe but low-energy:** at 1.55 V it sits above the electrolyte reduction window, so no SEI or plating forms, but it lowers the cell voltage by about 1.4 V versus graphite.

**Critical particle size for Si:** particles smaller than roughly 150 nm tend not to crack, which is why nano-Si and Si/C composites are used.

## 18. Electrolyte, SEI, separator and collectors

| Component | Typical data | Why it matters |
| --- | --- | --- |
| Electrolyte | 1 M LiPF₆ in EC:DMC (1:1), as in your slide | EC has a high dielectric constant and dissolves the salt; DMC lowers viscosity |
| Conductivity | ≈ 10 mS/cm at 25 °C | Sets ohmic (IR) drop |
| Stability window | Reduced below ≈ 0.8 V vs Li, oxidised above ≈ 4.3–4.5 V | Graphite (0.01–0.2 V) is outside the window, so it needs an SEI |
| SEI | 10–50 nm of LiF, Li₂CO₃, lithium alkyl carbonates | Blocks electrons, passes Li⁺; its growth costs Li and causes the first-cycle loss |
| Separator | PE/PP, ≈ 12–25 µm | Prevents short circuits, passes Li⁺ |
| Anode collector | Cu, ≈ 6–12 µm | Stable at low V, no alloying with Li |
| Cathode collector | Al, ≈ 10–20 µm | Passivated by an oxide/fluoride film at high V |

- **Why EC is essential:** it forms a stable SEI on graphite. Solvents such as PC co-intercalate with Li⁺ and exfoliate graphite. This also ties to your slide on *solvated Li⁺* entering the graphite: the solvation shell must be stripped at the surface (desolvation) before intercalation.
- **LiPF₆ hydrolysis:** LiPF₆ + H₂O → LiF + POF₃ + 2HF. Trace water therefore produces HF, which attacks the cathode and SEI. This is one cause of capacity fade.
- **Same logic for the aqueous limit:** water splits at 1.23 V, so aqueous cells are limited to roughly 1.5–2 V (lead-acid reaches 2.01 V only because of high H₂ overpotential on Pb).

## 19. Kinetics, diffusion and temperature (extrapolated)

**Solid-state diffusion time**

```latex
t \approx \frac{L^2}{D}
```

- Take D ≈ 10⁻¹⁰ cm²/s (approximate for Li in oxides and graphite) and particle or film length L = 10 µm = 10⁻³ cm: t ≈ 10⁻⁶ / 10⁻¹⁰ = 10⁴ s ≈ **2.8 h**.
- Because 1C is 1 h, a 10 µm path cannot keep up with 1C. Li⁺ piles up at the surface, which is the mechanism behind capacity loss and plating at high C-rate in your notes.
- For L = 1 µm, t ≈ 100 s. A 10× smaller length gives a 100× shorter time. This is why nano-sizing helps and why thick electrodes charge slowly.

**Temperature (Arrhenius)**

```latex
k = A\,e^{-E_a/RT}
```

- For E\_a = 50 kJ/mol, going from 25 °C (298.15 K) to 45 °C (318.15 K) gives a rate ratio of exp\[(50000/8.314)(1/298.15 − 1/318.15)\] ≈ **3.5×**.
- Plating is worst at low temperature (slow diffusion plus slow desolvation), so fast charging in the cold is dangerous.
- Heat from I²R and side reactions raises T further, which is the route to thermal runaway.

**Coulombic efficiency and fade**

- CE = discharge capacity / charge capacity. Your example gives 140/150 = **93.3%**.
- Retention after n cycles ≈ CEⁿ. At CE = 99.9%, 100 cycles retains 0.999¹⁰⁰ ≈ **90%**. At 99.5% it retains ≈ **61%**, and at 99% only ≈ **37%**. A tiny drop in CE is a big drop in life.

## 20. Worked examples with solutions (added)

**Example 1: pack energy.** A cell is 3.6 V, 5 Ah and 90 g. Energy = 3.6 × 5 = 18 Wh, so specific energy = 18 / 0.090 = **200 Wh/kg**. Four such cells in series give 14.4 V and 72 Wh (same method as your 62.9 Wh problem).

**Example 2: C-rate currents for a 3.4 Ah cell.**

| C-rate | Current (A) | Ideal time |
| --- | --- | --- |
| C/2 | 1.7 | 2 h |
| 1C | 3.4 | 1 h |
| 2C | 6.8 | 0.5 h |
| C/30 | 0.113 | 30 h |

**Example 3: coin-cell current.** An electrode has 10 mg active NMC811 at a practical 200 mAh/g, so capacity = 2 mAh. Then 1C = 2 mA, C/10 = 0.2 mA, and 2C = 4 mA.

**Example 4: ΔG from voltage.** ΔG = −nFE. For LCO‖Li at 4 V: ΔG = −96485 × 4 ≈ **−386 kJ/mol**. For LCO‖graphite at 3.8 V: ≈ **−367 kJ/mol**. The 19 kJ/mol difference is the "small loss" in your notes.

**Example 5: predicting XRD peaks (λ = 1.54056 Å).** Use 2θ = 2·arcsin(λ / 2d).

| Phase | d (Å) | 2θ (°) |
| --- | --- | --- |
| LCO (003) | 4.72 | 18.8 |
| Graphite (002) | 3.354 | 26.6 |
| LiC₁₂ (002) | ≈ 3.51 | ≈ 25.4 |
| LiC₆ (001) | ≈ 3.70 | ≈ 24.0 |

The order graphite → LiC₁₂ → LiC₆ moves to lower 2θ, matching the slide's peaks at about 26.5°, 25° and 24°.

**Example 6: anode mass using practical capacities.** 1 g LCO delivers ≈ 140 mAh. For an N/P ratio of 1.1, the anode must hold 154 mAh. Graphite at about 340 mAh/g practical needs 154 / 340 ≈ **0.45 g**. With Si (≈ 2500 mAh/g practical) it needs only ≈ **0.06 g**, about 7× less anode mass.

**Example 7: Li needed to alloy 1 g of Si.** Moles of Si = 1/28.09 = 0.0356 mol. For Li₁₅Si₄, Li = 3.75 × 0.0356 = 0.1335 mol = **0.93 g Li**. The alloy mass is 1.93 g, so the electrode gains about 93% in mass, along with about 300% in volume.

## 21. Na-ion vs Li-ion (added, ties to your Al-collector and NaPF₆ points)

| Property | Li-ion | Na-ion |
| --- | --- | --- |
| Ion radius | 0.76 Å | 1.02 Å |
| Standard potential vs SHE | −3.04 V | −2.71 V (about 0.33 V higher, so lower cell voltage) |
| Graphite anode | Works (LiC₆, 372 mAh/g) | Fails in carbonate electrolytes; hard carbon ≈ 300 mAh/g is used |
| Anode collector | Cu (Al alloys with Li) | Al works (Al does not alloy with Na) |
| Cathode collector | Al | Al |

Using Al on both sides lowers cost and weight, which is the motivation for Na-ion.

## 22. Practice problems with answers (added)

1. **LNMO (LiNi₀.₅Mn₁.₅O₄).** M = 6.94 + 0.5(58.69) + 1.5(54.94) + 64 = 182.70 g/mol, so Q\_th = 96500/(3.6 × 182.70) = **146.7 mAh/g**. It works near 4.7 V, so it needs a high-voltage electrolyte.
2. **LTO (Li₄Ti₅O₁₂ → Li₇Ti₅O₁₂).** M = 4(6.94) + 5(47.87) + 12(16.00) = 459.1 g/mol, n = 3, so Q\_th = 3 × 96500 / (3.6 × 459.1) = **175 mAh/g**.
3. **Si/graphite 10/90 by weight.** Q = 0.10(3579) + 0.90(372) = **692.7 mAh/g**. Compare 532 mAh/g for 5/95 in your notes.
4. **Fraction of Li removed in NMC811** if 205 mAh/g is delivered: x = 205 / 275.5 ≈ **0.74**.
5. **Peak shift.** A (003) peak moves from 18.80° to 18.10°. d goes from 4.72 Å to 4.90 Å, a +3.8% change in d, so c rises by the same fraction (c = 3d). Your notes' 18.70° → 18.10° gives 3.3%.
6. **Why does Si cycle worse than graphite at the same C-rate?** Roughly 300% vs 10% volume change per cycle, so Si cracks and reforms SEI each cycle, consuming Li and raising resistance.
7. **A cell charges 150 mAh and discharges 140 mAh in cycle 1. Estimate the Li lost.** 10 mAh ≈ 10 × 3.6 = 36 C of charge ≈ 3.7 × 10⁻⁴ mol Li, which went into SEI and side reactions.
