# CY 4050 – Lecture 2: Short Notes
*Anodes, SEI, current collectors, alloys, CV, EIS, solid-state batteries*

---

## 1. Graphite anode (LIB)
- Stores Li⁺ by **intercalation** → graphite intercalation compounds (GIC). Lithiation = charge, delithiation = discharge.
- Average discharge potential ≈ **0.1 V vs Li⁺/Li**.
- Volume change on lithiation ≈ **~10–20 %** (in-situ electrochemical dilatometry; thickness change). Electrolyte: 1 M LiPF₆ in EC:DMC.
- Charge/discharge curves are recorded at low rates (1/10 C, 1/100 C, 1/250 C) → staging plateaus; XRD (002) peak shifts on intercalation.
- **Coulombic efficiency** = Q_discharge / Q_charge. Ni-Cd: 70–90 %; LIB: ≈ 100 %.

## 2. Alloy-type anodes (Si, Sn)
- **Si**: stores Li via **Li–Si intermetallic** formation. **Sn**: Li–Sn alloy.
- Alloy electrodes undergo **huge volume change → particle cracking → pulverization**, loss of contact, continuous SEI growth.
- **Sn (LIB)**: theoretical capacity **997 mAh g⁻¹ (Li₄.₄Sn)**. Discharge sequence of Li–Sn:
  Li₂₂Sn₅ → Li₇Sn₂ → Li₁₃Sn₅ → Li₅Sn₂ → Li₇Sn₃ → LiSn (reverse order on lithiation; many 2-phase regions in the phase diagram appear as voltage plateaus).
- **Sn (SIB)**: Sn → NaSn₅ → α-NaSn → Na₉Sn₄ → Na₁₅Sn₄ (seen by in-situ XRD). Many two-phase regions of the equilibrium diagram are absent in the voltage curve; last three plateaus match NaSn, Na₉Sn₄, Na₁₅Sn₄. Sn/graphene composites used.
- Binders: PVDF, Na-CMC, SBS rubber, etc.

## 3. Solid Electrolyte Interphase (SEI)

**Why it forms**
- Electrolyte window is set by HOMO/LUMO of the electrolyte. If anode electrochemical potential **μ_A > LUMO** → electrolyte **reduction**; if cathode **μ_C < HOMO** → electrolyte **oxidation**. This is an unstable situation, so decomposition occurs (also for salt anions PF₆⁻, TFSI⁻, BF₄⁻).
- **Cell voltage (OCV) = (μ_A − μ_C)/e**
- **No organic solvent is stable against Li**; the LIB works only because of the passivating SEI.

**Composition / structure**
- Products can be solid, soluble and gaseous. Common phases: **LiF, Li₂O, Li₂CO₃, polymers, oligomers, semicarbonates**.
- Several simultaneous reactions. **Inner part**: fully reduced (LiF, Li₂O); **outer part**: partly reduced (Li₂CO₃, polymers).
- Polycrystalline (grain boundaries); transport via mobile defects/grain boundaries. Aurbach: 3–5 layers; Peled: mosaic of microphases.
- Poor ionic conductor → must be **very thin (typically tens of nm)** to minimise IR drop. Thickness depends on electrode and electrolyte.

**Wish list for the interface (all must hold)**
1. Ionically conductive for Li⁺ (a solid electrolyte)
2. Electronically insulating
3. Covers the surface yet flexible enough for volume change; chemically stable long term
- (Check the **Pilling–Bedworth ratio**.)

**Three cases**
| Interface | Result |
|---|---|
| Electronically + ionically conductive | Continuous decomposition |
| Electronically insulating + ionically conductive | **SEI formed (desired)** |
| Electronically + ionically insulating | Decomposition stops but Li⁺ can't move → battery doesn't work |

**Practical points**
- SEI forms mainly in the **first cycle**; not again if stable. Instability of SEI (cracking on cycling) → degradation.
- Higher upper cut-off voltage (e.g., LiCoO₂ 4.3 vs 4.5 V) gives more capacity but more degradation.
- **Reduction potentials vs Li/Li⁺**: VC ≈ 1.4 V; EC ≈ 1.36 V; PC ≈ 1.32 V; DMC/DEC ≈ 1.24 / 0.90 V (as per slide order); Li⁺ intercalation into graphite < 0.30 V. Solvents reduce *before* Li⁺ intercalates → SEI forms first.
- **PC** co-intercalates and exfoliates graphite (bad); **EC** forms a good SEI; **LiPF₆ + EC** is the standard.
- **Film-forming additives**: VC (vinylene carbonate), **FEC** (fluoroethylene carbonate; esp. for Si anodes).
- **Gas evolution** during SEI formation: mainly **ethylene and CO** (from EC decomposition).
- Solvents in LIB: EC, PC, DMC, DEC, THF, 2Me-THF, DME.
- Graphite surface groups change the SEI → mechanism is even more complex.
- **In-situ tools**: pressure cell (voltage, current density, temperature-controlled), **DEMS** (differential electrochemical mass spectrometry) for gas analysis.

**Flash points (fire risk)**: DMC 17 °C, EC 160 °C, diglyme 57 °C. Fires arise from **short circuit, overcharging, electrolyte breakdown** (flammable carbonates).

## 4. Current collectors
- **Cu** for anode (LIB); **Al** for cathode (LIB). In SIB, Al can be used for both (homework: why Cu for anode, why not Cu at cathode, why Al works as anode current collector in SIB – Al alloys with Li at low potential, but not with Na; Cu corrodes/dissolves at high potential, so unsuitable for the cathode side – see CV of Cu, 0–5 V vs Li/Li⁺).
- Corrosion of Cu and Al collectors is a degradation route.

## 5. Phase diagram & alloys
- **Solid solution**: mixing by **Fick's law diffusion** (A and B atoms interdiffuse).
- **Substitutional alloy**: foreign atom takes a lattice site (e.g., Cr³⁺ in Al₂O₃, Sn in Cu); neighbours in tension or compression depending on size.
- **Interstitial alloy**: foreign atom sits in voids (e.g., Fe₃C).
- Void radii (r = host atom radius): **r_tet = 0.225 r**, **r_oct = 0.414 r**; triangular, tetrahedral and octahedral voids in close-packed structures.
- **Hume-Rothery rules** (for solid-solution formation):
  1. Atomic radii differ by **≤ 15 %** (Li 0.88 Å–Na 1.16 Å: 28 % → hard; K 1.52–Rb 1.63 Å: 11 % → exists)
  2. **Same/similar crystal structure** (Mo–W BCC; Ag–Au, Cu–Ni FCC)
  3. **Similar electronegativity** (large difference → intermetallic compounds)
  4. **Same valency** (complete solubility); a metal dissolves a higher-valency metal more readily than vice versa.

## 6. Cyclic voltammetry (CV)
- Potential swept linearly, current measured. Example redox couple: Fe³⁺ + e⁻ ⇌ Fe²⁺, Fc⁺ + e⁻ ⇌ Fc. Current governed by **mass transport** to the electrode through the **diffusion layer**.
- **Randles–Ševčík equation**
  - General: **i_p = 0.446 n F A C⁰ (n F v D / R T)^½**
  - At 25 °C: **I_p = 2.69×10⁵ · n^(3/2) · A · D^(1/2) · C · v^(1/2)**
  - I_p (A), A (cm²), D (cm² s⁻¹), C (mol cm⁻³), v (V s⁻¹), n electrons, F Faraday constant, R = 8.314 J K⁻¹ mol⁻¹, T temperature.
- **I_p ∝ v^½** (diffusion-controlled): plot I_p vs √v is a straight line; slope gives D.
- Rearranged: **D = [ I_p / (2.69×10⁵ n^(3/2) A C v^(1/2)) ]²**
- Scaling between scan rates: **I_p2 / I_p1 = √(v₂/v₁)**
- CV of graphite: SEI reduction peak in the **first cycle**, absent later if SEI is stable. CV of LiCoO₂ shows Li⁺ (de)intercalation redox peaks.

**Worked examples (slides)**
- Two-electron reversible, I_p = 85 µA, A = 0.20 cm², C = 2.0 mM (= 2.0×10⁻⁶ mol cm⁻³), v = 0.050 V s⁻¹ → slide answer D = 1.24×10⁻⁵ cm² s⁻¹. *(When I recompute with the formula and these inputs I get ≈ 1.56×10⁻⁶ cm² s⁻¹, so double-check this one against your lecture.)*
- I_p = 40 µA at 25 mV s⁻¹ → at 100 mV s⁻¹: I_p2 = 40 × √(100/25) = **80 µA**.

## 7. Electrochemical impedance spectroscopy (EIS)
- AC potential applied over **~1 MHz to 0.1 mHz**. Displayed as a **Nyquist plot** (−Z_imag vs Z_real).
- **Nyquist (Randles circuit)**
  - **High frequency**: intercept = solution resistance **R_s**
  - **Mid frequency**: semicircle = charge-transfer resistance **R_ct** with double-layer capacitance (ω = 1/RC at the top); right end at R_s + R_ct
  - **Low frequency**: 45° straight line = **Warburg (diffusion) impedance**, slope = σ (Warburg coefficient)
- Impedance of SEI/cell grows with time/cycling (compare spectra of different systems).
- **Capacitor**: Z_C = 1/(jωC) = −j/(ωC); |Z_C| = 1/(ωC); ω = 2πf; j = √−1. Impedance **decreases** with frequency.
- **Parallel RC**: 1/Z = 1/R + 1/Z_C ⇒ **Z = R / (1 + jωRC)**, **|Z| = R / √(1 + (ωRC)²)**
- **Warburg coefficient**: **σ = RT / (√2 n² F² A C √D)** ⇒ D = [RT / (√2 n² F² A C σ)]²

**Worked examples (slides)**
- R = 200 Ω, C = 20 µF parallel: |Z| at 10 Hz = 193.95 Ω (ωRC = 0.2513), at 100 Hz ≈ 74.5 Ω (slide; I get ≈ 73.9 Ω), at 1000 Hz = 7.95 Ω. Low f → resistor dominates (|Z| → R); high f → capacitor shorts it (|Z| → 0).
- C = 100 µF, f = 100 Hz: ω = 628.32 rad/s; Z_C = −j15.92 Ω, |Z_C| = 15.92 Ω; at 1 kHz |Z_C| = 1.592 Ω.
- Warburg: R = 8.314, T = 298 K, n = 1, F = 96485, A = 1 cm², C = 1×10⁻³ mol cm⁻³, σ = 100 Ω s⁻¹ᐟ² → D = (RT/(√2 n²F²ACσ))² ≈ 3.5×10⁻¹² cm² s⁻¹ (not shown on slide; my calculation).

## 8. All-solid-state Li battery (ASSB)
- Structure: **Li metal anode | solid electrolyte (e.g., Li₃PS₄, Li₆PS₅Cl) | cathode composite (LiCoO₂ / NMC with SE)**. Alternative: Si or Sn/graphite + Li₃PS₄ composite anode.
- Li metal: specific capacity **3860 mAh g⁻¹**; energy density 300–600 Wh (per kg, as on slide); wide potential window ~5 V. Solid electrolyte removes the **flammable liquid electrolyte** safety problem.
- **Ion migration in solids**: via vacancies/interstitials hopping over an energy barrier.
  - Arrhenius: **k = A exp(−E_a/RT)**
  - Hopping: **p = D₀ exp(−Δg_m / kT)** (Δg_m = migration barrier; bottlenecks: triangular, tetrahedral and octahedral sites)
  - **Total ionic conductivity: σ = q n u = σ₀ T^m exp(−E_a/k_B T)** (q charge, n carrier concentration, u mobility)
- **Stability window** of SE: reduction at the anode side (Li-rich interphase, vacancy depletion) and oxidation at the cathode side (Li-poor interphase), producing space-charge layers.
- **Challenges**
  1. Poor interfacial contact (voids at SE/electrode interface)
  2. **Li dendrite** formation (Li⁺ + e⁻ → Li) → short circuit
  3. SE decomposition below ~0.2 V vs Li⁺/Li: **Li₃PS₄ → Li₃P + Li₂S**; resistive layer (acts like an SEI, but raises R_SE and reduces conductivity)
  - Fix: **Indium interlayer** (In + Li⁺ + e⁻ → InLi) or coated Li; drawbacks: In is expensive and dense (lowers energy density).
- Fabrication: anode composite (e.g., Sn/graphite + 30 wt% Li₃PS₄) pressed with the SE separator and Li.

---
*Note: the slides contain many figures with no text. Slides that were figures only (e.g., SEI schematics, DEMS plots, phase diagrams, orbital diagrams from Bard & Faulkner) are summarised from their titles and surrounding text.*
