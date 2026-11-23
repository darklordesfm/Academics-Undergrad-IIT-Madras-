# Electrode Kinetics — Reference Electrodes, Butler–Volmer/Tafel Analysis, Mass Transport & Techniques
## Consolidated Formula Sheet & Notes

---

# PART A — Reference & Working Electrodes

## A.1 Polarizable vs. Non-polarizable Electrodes
**Non-polarizable electrode** (e.g., Ag/AgCl):
- Reversible chemical reaction at the electrode; electrons transfer easily through this reaction.
- Because it's highly reversible, it can **supply/accept current while its potential changes only slightly**.
- Current passes → potential changes **slightly**. → Good for stable reference potentials.

**Polarizable electrode** (e.g., inert Pt wire):
- No easy Faradaic (redox) reaction available to carry current.
- Charge instead **accumulates at the interface** (behaves like a capacitor).
- Current passes → potential changes **significantly**.

**Conclusion:** A good reference electrode needs a **constant, stable potential** → must be **non-polarizable**.
- A *perfectly polarizable* electrode: no charge crosses the interface on passing current (pure capacitor behavior).
- A *perfectly non-polarizable* electrode: current passes freely across the interface, requiring no energy for the transition (e.g., Ag/AgCl/KCl).

## A.2 The Three Electrodes
- **Working Electrode (WE):** the electrode at which the electrochemical reaction under investigation occurs.
- **Counter/Auxiliary Electrode (CE):** completes the current circuit; supplies/absorbs electrons at a rate equal and opposite to the WE; plays **no role** in potential measurement.
- **Reference Electrode (RE):** non-polarizable; maintains a stable, known potential independent of cell current; the fixed voltage reference against which WE potential is measured.

## A.3 Why Three-Electrode > Two-Electrode Measurement
- A 3-electrode cell **separates the current-carrying electrode (CE) from the potential-measuring electrode (RE)**.
- This greatly **reduces errors from counter-electrode polarization**, allowing WE potential to be **controlled and measured much more accurately**.
- Common reference electrodes: **Ag/AgCl, Saturated Calomel Electrode (SCE), Hg/HgO**.

## A.4 Sacrificial Anodes
- A piece of a **more reactive (more easily oxidized/more electropositive) metal**, electrically connected to a structure, to prevent that structure from corroding.
- The sacrificial anode **undergoes oxidation (corrosion) preferentially**, supplying electrons to the protected metal — making the protected metal the **cathode**.
- As the anode is consumed, it must eventually be **replaced**.
- **Zinc** is commonly used to protect steel/iron: more easily oxidized than Fe, relatively inexpensive, more electropositive → gets oxidized instead of the iron structure.

---

# PART B — Mass Transport & Interfacial Fundamentals

## B.1 Three Mechanisms of Mass Transport
1. **Migration:** driving force = electric field in solution. Usually **suppressed experimentally** by adding a high concentration of **supporting electrolyte**.
2. **Convection:** driving force = external (mechanical) energy — stirring, rotating the electrode, pumping the liquid.
3. **Diffusion:** driving force = gradient in chemical potential (caused by concentration gradient); dominant when no external electrical or mechanical energy input promotes movement.

## B.2 Double-Layer Capacitance (Recap)
- Metal dipped in solution → discontinuity at interphase; near-surface properties differ from bulk.
- **Double-layer capacitance, $C_{dl}$**: arises from charge separation between the two phases in contact.
- Confined to a thin region extending **~1–10 nm** from the interface.
- Depends on: **potential, solution composition, solvent, and the metal** itself.

## B.3 Heterogeneous Rate Constant
- Describes how fast **electron transfer** occurs between an electrode and a species in solution.
- **Units: cm/s** (a surface/interfacial rate constant, distinct from bulk homogeneous rate constants).
- "Heterogeneous" = the electron-transfer reaction occurs **across the electrode–solution interface**.
- **Key analogy:** rate of reaction (chemical kinetics) ↔ **current density** (electrochemistry).

---

# PART C — Overpotential & the Butler–Volmer Equation

## C.1 Overpotential: Definition & Types
$$\eta = E_{applied} - E_{eq}$$

- $\eta = 0$ at equilibrium (no net current).
- **Sign convention:** $\eta_{oxidation}\ (\text{anodic}) > 0$; $\eta_{reduction}\ (\text{cathodic}) < 0$.

**Three overpotential components** (sources of deviation from equilibrium potential):
- $\eta_{act}$ — **activation overpotential** (charge-transfer kinetics barrier).
- $\eta_{conc}$ — **concentration (mass-transport) overpotential** (depletion/enrichment of reactant/product at the surface).
- $\eta_{ohm}$ — **ohmic overpotential** (IR drop through solution/cell resistance).

$$V_{measured} = V_{equilibrium} \pm \eta_{act} \pm \eta_{conc} \pm \eta_{ohm}$$

## C.2 From Rate Law to Current Density
For $A \rightarrow$ product, with an **Arrhenius-type rate constant** $k = \theta\,e^{-E_a/RT}$ (θ = pre-exponential/frequency factor):
$$i = nF\times\text{rate} = nFk[A] = nF\theta e^{-E_a/RT}[A]$$

- The **activation energy $E_a$ itself depends on potential** (and hence on overpotential η) — this potential-dependence of $E_a$ is what generates the Butler–Volmer form below.

## C.3 The Butler–Volmer Equation
**General form (net current density as sum of anodic and cathodic partial currents):**
$$i = i_0\left[\exp\left(\dfrac{\alpha_a F\eta}{RT}\right) - \exp\left(\dfrac{-\alpha_c F\eta}{RT}\right)\right]$$

- (Symmetric-α version, single transfer coefficient α with $\alpha_c = 1-\alpha$):
$$i = i_0\left[\exp\left(\dfrac{\alpha F\eta}{RT}\right) - \exp\left(\dfrac{-(1-\alpha)F\eta}{RT}\right)\right]$$

- $i_0$ = **exchange current density** — the (equal) magnitude of the forward and reverse partial current densities **at equilibrium** ($\eta=0$).
- $\alpha_a,\alpha_c$ (or $\alpha, 1-\alpha$) = **anodic/cathodic transfer (symmetry) factors**, typically $0<\alpha<1$; for a simple one-electron step often $\alpha_a+\alpha_c=1$.

**Derivation sketch (concentration-explicit form), e.g. for $R^+ + e^- \rightarrow R$:**
$$i_k = nFk^{\circ}[\,]\left[e^{\alpha F\eta/RT} - e^{-(1-\alpha)F\eta/RT}\right]$$

## C.4 Exchange Current Density — Physical Meaning
- At $\eta = 0$: $i = i_0(1-1) = 0$ → **no net current**, but this does **not** mean no reaction — forward and reverse reactions proceed at **equal, nonzero rates**, defined by:
$$i_0\,e^{\alpha F\eta/RT} = i_0\,e^{-(1-\alpha)F\eta/RT} \quad (\text{at }\eta=0,\text{ both equal } i_0)$$
- **Large $i_0$** → fast intrinsic (facile) charge-transfer kinetics → only a **small overpotential** needed to drive a given current (steep i–η curve near η=0).
- **Small $i_0$** → sluggish kinetics → a **larger overpotential** is required to drive the same current.
- (Butler–Volmer plot: curves for $i_0 = 1, 10, 100\ mA/cm^2$ — the higher-$i_0$ curve rises far more steeply away from η=0.)

## C.5 Activation Energy Picture / Symmetry Factor
- Reaction-coordinate diagram: applying an overpotential $\eta$ shifts the reactant/product energy levels by $nF\eta$.
- This total energy shift is **partitioned** between raising the cathodic barrier and lowering the anodic barrier (or vice-versa) according to the transfer coefficient:
  - Change in cathodic activation energy $\propto (1-\alpha)nF\eta$
  - Change in anodic activation energy $\propto \alpha nF\eta$
- α (symmetry factor) reflects **how symmetric the transition state is** between reactant and product configurations along the reaction coordinate (α = 0.5 → perfectly symmetric barrier response).

---

# PART D — Limiting Cases of the Butler–Volmer Equation

## D.1 Linearized Butler–Volmer (Low Overpotential, |η| small)
Using $e^{x}\approx 1+x$ for small x:
$$i \approx i_0\left[\left(1+\dfrac{\alpha_a F\eta}{RT}\right) - \left(1-\dfrac{\alpha_c F\eta}{RT}\right)\right] = i_0\dfrac{(\alpha_a+\alpha_c)F\eta}{RT} = \dfrac{i_0 nF\eta}{RT}$$

- **Linear (Ohmic-like) relation** between current and overpotential near equilibrium.
- Defines the **charge-transfer resistance:**
$$R_{ct} = \left(\dfrac{d\eta}{di}\right)_{\eta\to0} = \dfrac{RT}{nFi_0}$$

## D.2 Tafel Equation (High Overpotential, large |η|)
- At **large positive η** (strongly anodic), the cathodic (reverse) term becomes negligible:
$$i \approx i_0\exp\left(\dfrac{\alpha_a F\eta}{RT}\right) \quad (\text{anodic Tafel branch})$$
- At **large negative η** (strongly cathodic), the anodic term becomes negligible:
$$i \approx -i_0\exp\left(\dfrac{-\alpha_c F\eta}{RT}\right) \quad (\text{cathodic Tafel branch})$$

**Tafel form (rearranged, base-10 log):**
$$\eta = b\log_{10}\left(\dfrac{i}{i_0}\right) \qquad\text{or equivalently}\qquad \log_{10}i = \log_{10}i_0 + \dfrac{\alpha F\eta}{2.303\,RT}$$

**Tafel slope:**
$$b = \dfrac{2.303\,RT}{\alpha nF} \qquad\Longrightarrow\qquad \alpha = \dfrac{2.303\,RT}{nbF}$$

- **From a Tafel plot (η vs. log i):**
  - **Slope** = $b = \dfrac{\Delta\eta}{\Delta\log i}$ (units: V/decade or mV/decade) → gives α (knowing n).
  - **Intercept** (extrapolated to η = 0) = $\log_{10}i_0$ → gives the exchange current density.
- **Validity:** the Tafel (single-exponential) approximation is justified only when |η| is large enough that the opposite-direction exponential term is negligible (rule of thumb: several tens of mV, i.e., roughly $|\eta| \gtrsim 100$–120 mV for α≈0.5); at low η the full Butler–Volmer form (or its linearization) must be used instead.

---

# PART E — Mass-Transport-Controlled Techniques

## E.1 Rotating Disk Electrode (RDE) & Diffusion Layer Thickness
- A rotating electrode (e.g., gold disk) drags fresh electrolyte to the surface via **hydrodynamic flow** — reactant is continuously brought from bulk to surface **at a constant rate**.
- **Diffusion layer thickness δ decreases as rotation speed (rpm/ω) increases** — illustrated by boundary layers shrinking from 300 → 600 → 900 → 1200 rpm.
- Concentration profile: linear approximation from $C_{surface}$ (at electrode, inside IHP/OHP) up to $C_{bulk}$ across the diffusion layer thickness.
- **Standard relation (Levich theory)** underlying this behavior:
$$\delta \propto \omega^{-1/2}$$
i.e., the diffusion layer thins as the square root of rotation rate increases — enabling systematic control of the **mass-transport-limited current** via rotation speed.

## E.2 Koutecky–Levich–Type Analysis
- Total observed current combines a **kinetic (activation-limited)** contribution and a **mass-transport (rotation-dependent)** contribution:
$$\dfrac{1}{i_{obs}} = \dfrac{1}{i_k} + \dfrac{1}{i_L(\omega)}$$
- A plot of $\dfrac{1}{i_{obs}}$ vs. $\dfrac{1}{\sqrt{\omega}}$ is linear; the **intercept** (at $1/\sqrt{\omega}\to0$, i.e. infinite rotation) gives the purely **kinetic current**, $1/i_k$ — isolating charge-transfer kinetics from mass-transport limitations.

## E.3 Cottrell Equation (Chronoamperometry)
For an **instantaneous potential step** at a planar electrode:
$$i(t) = \dfrac{nFAD^{1/2}C^*}{\pi^{1/2}t^{1/2}} \qquad\Longrightarrow\qquad i(t)\propto D^{1/2}t^{-1/2}$$

- Diffusion layer **grows as $t^{1/2}$**; measured current **decays as $t^{-1/2}$**.

## E.4 Randles–Ševčík Equation (Cyclic Voltammetry — "CV analog of Cottrell")
For a **linear potential sweep** at scan rate ν:
$$i_p = 0.4463\,nFAC^*\left(\dfrac{nF\nu D}{RT}\right)^{1/2} \qquad\Longrightarrow\qquad i_p\propto D^{1/2}\nu^{1/2}$$

- Conceptual link: each infinitesimal potential step during the sweep produces a tiny "mini-Cottrell" current response; **integrating all these mini-Cottrell contributions over the full sweep** yields the Randles–Ševčík expression for the peak current.
- CV waveform: $V_t = V_i + \nu t$ (linear ramp), producing a characteristic anodic/cathodic peak pair (e.g., for a reversible redox probe such as $[Fe(CN)_6]^{3-/4-}$).

## E.5 Total Current — Contributions from All Transport Modes
$$i = i_{migration} + i_{diffusion} + i_{convection}$$
- In a well-designed experiment (excess supporting electrolyte, controlled hydrodynamics), migration and/or convection can be minimized/controlled so that the current predominantly reflects diffusion (or a chosen convective regime, e.g., RDE), simplifying kinetic analysis.

---

# PART F — HER, OER, ORR (Key Multi-Electron Electrode Reactions)

## F.1 Hydrogen Evolution Reaction (HER)
- **Acidic media:** $2H^+ + 2e^- \rightarrow H_2(g)$  (n = 2)
- **Alkaline media:** $2H_2O + 2e^- \rightarrow H_2(g) + 2OH^-$  (n = 2)

## F.2 Oxygen Evolution Reaction (OER)
- **Acidic media:** $2H_2O \rightarrow O_2(g) + 4H^+ + 4e^-$  (n = 4)
- **Alkaline media:** $4OH^- \rightarrow O_2(g) + 2H_2O + 4e^-$  (n = 4)
- OER is kinetically sluggish (large overpotentials, small $i_0$) — a classic system for **Tafel-slope analysis** (see Tutorial 5, Q4 below).

## F.3 Oxygen Reduction Reaction (ORR)
- **4-electron pathway (acidic):** $O_2 + 4H^+ + 4e^- \rightarrow 2H_2O$  (n = 4)
- **4-electron pathway (alkaline):** $O_2 + 2H_2O + 4e^- \rightarrow 4OH^-$  (n = 4)
- **2-electron pathway (peroxide route):** $O_2 + 2H^+ + 2e^- \rightarrow H_2O_2$  (n = 2) — generally less desirable (lower efficiency, reactive peroxide intermediate).
- HER, OER, and ORR are the archetypal reactions analyzed using Butler–Volmer/Tafel kinetics (§C–D) because they are **multi-step, multi-electron** processes with experimentally accessible exchange current densities and Tafel slopes that reveal mechanism.

---

# PART G — pH Electrodes (Recap)

- A **pH meter is a special voltmeter**: measures the potential difference across a thin **glass membrane**.
$$E_{membrane} = E_{inner}-E_{outer} = 0.0592\log\dfrac{[H^+]_{inner}}{[H^+]_{outer}}$$
- Glass membrane: dry glass core (~50 μm) between two **hydrated gel layers** (~5–100 nm) that generate the pH-responsive potential via ion exchange.
- **Residual liquid-junction potential (LJP)** is not perfectly eliminated (a few mV possible); at 25 °C, ideal response ≈ **59.16 mV/pH**, so a 3 mV LJP error ≈ 0.05 pH units.
- **Calibration** with standard buffers (pH 4, 7, 10) fixes offset & slope but does **not** fully correct a *changing* residual LJP between buffer and sample.
- Manufacturers use **concentrated KCl** reference electrolyte with a controlled-flow junction to keep the local composition reproducible.

---

# PART H — Tutorial 5: Worked-Problem Theory (Butler–Volmer / Tafel)

## H.1 Q1 — Net Current from Full Butler–Volmer (Symmetric α)
Given: $i_0 = 1.0\times10^{-3}\ A/cm^2$, $\alpha_a=\alpha_c=0.5$, T = 298 K.
$$i = i_0\left[\exp\left(\dfrac{\alpha_aF\eta}{RT}\right)-\exp\left(\dfrac{-\alpha_cF\eta}{RT}\right)\right]$$
- At $\eta=+50\ mV$: $\dfrac{\alpha F\eta}{RT}=\dfrac{(0.5)(96500)(0.050)}{(8.314)(298)}=0.9737$
$$i = i_0[e^{0.9737}-e^{-0.9737}] = 10^{-3}[2.648-0.378]\approx 2.27\times10^{-3}\ A/cm^2\ (\text{anodic, net oxidation})$$
- At $\eta=-50\ mV$: by symmetry ($\alpha_a=\alpha_c$), the result simply **flips sign**: $i\approx -2.27\times10^{-3}\ A/cm^2$ (cathodic, net reduction).
- **Key insight:** BV is symmetric about $\eta=0$ **only when** $\alpha_a=\alpha_c$; this symmetry breaks down when $\alpha_a\neq\alpha_c$.

## H.2 Q2 — Exact BV vs. Anodic Tafel Approximation, % Error
- **Exact:** use the full two-exponential BV equation at $\eta=+200\ mV$ (same $i_0$, α, T as Q1).
- **Tafel approximation (anodic, high-η limit):** drop the cathodic term entirely:
$$i_{Tafel} \approx i_0\exp\left(\dfrac{\alpha_aF\eta}{RT}\right)$$
- **% error:**
$$\%\,\text{error} = \dfrac{i_{Tafel}-i_{exact}}{i_{exact}}\times100\%$$
- At larger η (200 mV ≫ 50 mV), the neglected cathodic exponential term is already very small, so the Tafel approximation error should be small — **justifying** Tafel-approximation use at sufficiently high overpotential (the check performed here formalizes that justification).

## H.3 Q3 — Linearizing Butler–Volmer at Low Overpotential
- Using $e^x\approx1+x$ for small $\dfrac{\alpha F\eta}{RT}$:
$$i \approx i_0\dfrac{(\alpha_a+\alpha_c)F\eta}{RT} = \dfrac{i_0nF\eta}{RT}$$
- This is the **linear/Ohmic regime**; slope $\dfrac{di}{d\eta}=\dfrac{i_0nF}{RT}$ defines the **charge-transfer resistance** $R_{ct}=\dfrac{RT}{nFi_0}$ (see §D.1).

## H.4 Q4 — OER: Extracting Current Density & Transfer Coefficient from Tafel Data
Given: $\eta = 0.456\ V$, Tafel slope $b = 120\ mV/decade = 0.120\ V/decade$, $T=15^{\circ}C=288.15\ K$, $i_0=6.9\times10^{-7}\ A\,m^{-2}$, OER → **n = 4**.

**Step 1 — Current density from Tafel equation:**
$$\eta = b\log_{10}\left(\dfrac{i}{i_0}\right) \Rightarrow \dfrac{0.456}{0.120}=\log_{10}\left(\dfrac{i}{6.9\times10^{-7}}\right) \Rightarrow \dfrac{i}{6.9\times10^{-7}}=10^{3.8}$$
$$i \approx 4.35\times10^{-3}\ A\,m^{-2}$$

**Step 2 — Transfer coefficient from the Tafel slope:**
$$b = \dfrac{2.303RT}{\alpha nF} \Rightarrow \alpha = \dfrac{2.303RT}{nbF} = \dfrac{(2.303)(8.314)(288.15)}{(4)(0.120)(96485)} \approx 0.12$$

---

# PART I — Brief Recap: Solid-State / LiCoO₂ / Spinel Content (Continuity Slides)

*(These topics were covered in full detail in the previous Week-2 solid-state formula sheet — restated here briefly for continuity, since the same slides recurred in this lecture.)*

- **LiCoO₂ (O3) stability limits:** $Li_{1-x}CoO_{2-\delta}$ — O3 structure maintained for $0.5\le(1-x)\le1.0$; O3+P3 coexist for $0\le(1-x)\le0.45$; $NO_2BF_4$ used for rapid chemical delithiation to metastable P3 (vs. O1, which is chemically synthesized directly).
- $Li_{1-x}Ni_{0.85}Co_{0.15}O_{2-\delta}$: O3 maintained for $0.25\le(1-x)\le1.0$; O3+O3′ coexist below that; O3′ has a **smaller c-parameter** than O3 (stronger O–O bonding across the van der Waals gap).
- **Spinel family site energies:** $LiMn_2O_4, LiTi_2O_4, LiV_2O_4$ all share a **CCP oxide array**; moving from LiCoO₂ → LiMn₂O₄ **significantly reduces cost**. $Mn^{3+/4+}$ at 16d (Oh); $Li^+$ at 8a (Td, reversible); 16c (Oh) empty. $Li_{1-x}Mn_2O_4$: ~4 V, ~130 mAh/g. Additional Li⁺ insertable at 16c at ~3 V (same redox couple, **different site energy** → different voltage). **Mn disproportionation** ($2Mn^{3+}\rightarrow Mn^{4+}+Mn^{2+}$) dissolves Mn²⁺ into electrolyte, contaminating the anode. $LiTi_2O_4$ → only 1.5 V; $LiV_2O_4$ → structural change, low ~3 V. Attempts at $LiCo_2O_4$/$LiNi_2O_4$ spinels failed (oxygen loss on synthesis).
- **Co vs. Mn cathode trade-off:** Co → reversible & electrochemically stable, but thermally unstable & costly. Mn → thermally stable & cheap, but prone to TM mixing and comparatively electrochemically inert in some configurations.

---

# Quick-Reference Formula Box

$$\eta = E_{applied}-E_{eq} \qquad i = i_0\left[e^{\alpha_aF\eta/RT}-e^{-\alpha_cF\eta/RT}\right]\ \text{(Butler–Volmer)}$$
$$\text{Low }\eta:\ i\approx\dfrac{i_0nF\eta}{RT},\ R_{ct}=\dfrac{RT}{nFi_0} \qquad \text{High }\eta:\ \eta=b\log_{10}(i/i_0),\ b=\dfrac{2.303RT}{\alpha nF}$$
$$i(t)=\dfrac{nFAD^{1/2}C^*}{\pi^{1/2}t^{1/2}}\ (\text{Cottrell}) \qquad i_p=0.4463\,nFAC^*\left(\dfrac{nF\nu D}{RT}\right)^{1/2}\ (\text{Randles–Ševčík})$$
$$\delta\propto\omega^{-1/2}\ (\text{RDE}) \qquad \dfrac{1}{i_{obs}}=\dfrac{1}{i_k}+\dfrac{1}{i_L(\omega)}\ (\text{Koutecky–Levich})$$
$$HER:\ 2H^++2e^-\to H_2\ (n=2) \qquad OER:\ 2H_2O\to O_2+4H^++4e^-\ (n=4) \qquad ORR:\ O_2+4H^++4e^-\to2H_2O\ (n=4)$$
$$E_{membrane}=0.0592\log\dfrac{[H^+]_{in}}{[H^+]_{out}}\ (\text{pH glass electrode})$$
