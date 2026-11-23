# CY 4050 — Electrochemical Technology
## Consolidated Formula Sheet & Notes (Fundamentals + Tutorials 2 & 3)

---

## 1. Charged Surfaces & Electrical Double Layer

- A surface becomes charged by **electron transfer, ion adsorption,** or an **externally applied potential**.
- Oppositely charged ions accumulate near the surface → **electrical double layer** = compact layer (near surface) + diffuse layer (into bulk).
- The double layer behaves like a **parallel-plate capacitor**.

**Double-layer capacitance:**
$$C_{dl} = \dfrac{\varepsilon A}{d}$$
where ε = permittivity of medium, A = electrode area, d = separation distance (charge layer thickness).

---

## 2. Metal in Its Own Salt Solution (e.g., Zn in ZnSO₄)

$$Zn(s) \rightleftharpoons Zn^{2+}(aq) + 2e^-$$

- Electrons remain on the rod; Zn²⁺ accumulates near the surface → charge separation → **equilibrium electrode potential**.
- At equilibrium: rate of dissolution = rate of deposition → **no net current** on an isolated electrode.
- Potential depends on Zn²⁺ activity via the **Nernst equation**.

**General Nernst Equation:**
$$E = E^{\circ} - \dfrac{RT}{nF}\ln Q \quad\Longrightarrow\quad E = E^{\circ} - \dfrac{0.05916}{n}\log Q \ \ (\text{at } 298\ \text{K})$$

- R = 8.314 J K⁻¹mol⁻¹, F = 96485 C mol⁻¹, T in K, n = electrons transferred, Q = reaction quotient.

---

## 3. Band Theory of Solids

- Many atomic orbitals combine in a solid → broaden into **allowed energy bands** separated by **forbidden band gaps**.
- **Valence band:** highest band normally occupied by electrons.
- **Conduction band:** higher-energy band where electrons can move freely.
- **Metals:** partially filled/overlapping bands (small/no gap).
- **Semiconductors:** small band gap.
- **Insulators:** large band gap.
- Electrical conductivity and electron-transfer behavior depend on the **density and occupancy of electronic states**.

---

## 4. Fermi Level & Redox Equilibration

- **Fermi level (E_F):** highest occupied electron energy level at 0 K; represents a solid's electron electrochemical potential (tendency of electrons to leave/enter the material).
- On contact, electrons transfer until the **metal Fermi level = solution redox level** → interfacial charge + potential drop.
- Electron flow **metal → solution** = reduction (of solution species).
- Electron flow **solution → metal** = oxidation (of solution species), reduction of metal charge.

---

## 5. Electrochemical Series

- Arranges redox couples by **standard reduction potential, E°** (vs. SHE).
- **More positive E°** → stronger tendency to be reduced → stronger **oxidizing agent**.
- **More negative E°** → stronger tendency to be oxidized (in reduced form) → stronger **reducing agent**.

$$E^{\circ}_{cell} = E^{\circ}_{cathode} - E^{\circ}_{anode}$$

- **E°cell > 0** → spontaneous reaction under standard conditions (actual E depends on activities/temperature via Nernst).

---

## 6. Galvanic vs. Electrolytic Cells

| Feature | Galvanic Cell | Electrolytic Cell |
|---|---|---|
| Reaction | Spontaneous | Non-spontaneous (driven by external supply) |
| Energy | Chemical → Electrical | Electrical → Chemical |
| Anode | Negative (−) | Positive (+) |
| Cathode | Positive (+) | Negative (−) |
| Always true | Oxidation at anode; Reduction at cathode | Oxidation at anode; Reduction at cathode |

---

## 7. Cell Notation

- Written **anode → cathode** (left to right).
- **|** = phase boundary. **||** = salt bridge / separator (eliminates/minimizes junction potential).
- Same-phase species separated by commas. Inert conductors (e.g., Pt) included when no conducting solid redox species is present.

**Example (Daniell cell):**
$$Zn(s)\,|\,Zn^{2+}(aq)\,||\,Cu^{2+}(aq)\,|\,Cu(s)$$

- Conventionally, electrons flow externally from the **left-hand anode → right-hand cathode**.

---

## 8. Applied Example: Electrorefining of Copper

- **Goal:** Convert impure Cu → high-purity Cu.
- **Anode:** impure Cu slab. **Cathode:** pure Cu (or SS starter sheet). **Electrolyte:** acidified CuSO₄.

$$\text{Anode: } Cu \rightarrow Cu^{2+} + 2e^- \qquad \text{Cathode: } Cu^{2+} + 2e^- \rightarrow Cu$$

- Anode loses mass, cathode gains high-purity Cu.
- Less noble impurities (Fe, Zn) dissolve but don't deposit (controlled cathode potential).
- Noble metals (Ag, Au, Pt) collect as **anode slime**.

---

## 9. Conductivity & Kohlrausch's Law

$$\Lambda_m = \dfrac{\kappa}{c}$$
Λm = molar conductivity, κ = conductivity of solution (1/ρ), c = concentration.

$$\alpha = \dfrac{\Lambda_m}{\Lambda_m^{\circ}}$$
α = degree of dissociation, Λm° = limiting molar conductivity (infinite dilution).

**Kohlrausch's Law of Independent Migration of Ions:**
$$\Lambda_m^{\circ} = \nu_+\lambda_+^{\circ} + \nu_-\lambda_-^{\circ}$$
ν₊, ν₋ = number of cations/anions per formula unit; λ°₊, λ°₋ = limiting ionic molar conductivities.

**Conductivity of a sparingly soluble salt (subtract solvent background):**
$$\kappa_{salt} = \kappa_{solution} - \kappa_{water}$$

**Solubility from conductivity data:**
$$S = \dfrac{\kappa_{salt}}{\Lambda_m^{\circ}}$$

> **Worked logic (AB₂-type salt):** $\Lambda_m^{\circ}(AB_2) = \lambda^{\circ}(A^{2+}) + 2\lambda^{\circ}(B^-)$, then apply S = κ_salt/Λm°.

---

## 10. Concentration Cells

**Example:** $Zn(s)\,|\,Zn^{2+}(0.010\ M)\,||\,Zn^{2+}(1.00\ M)\,|\,Zn(s)$

- Both electrodes are the **same material**, so **E° = 0** — driving force comes purely from the **concentration difference** (ΔG of dilution), not from differing chemical identity.
- **Dilute side = anode (oxidation):** $Zn \rightarrow Zn^{2+} + 2e^-$ (system "tries" to equalize concentration by dissolving more metal into the dilute side).
- **Concentrated side = cathode (reduction):** $Zn^{2+} + 2e^- \rightarrow Zn$
- **Overall:** $Zn^{2+}(1.00\ M) \rightarrow Zn^{2+}(0.010\ M)$ (net transfer of ions from high to low concentration compartment)

**Cell potential:**
$$E_{cell} = E^{\circ}_{cell} - \dfrac{0.05916}{n}\log\dfrac{[Zn^{2+}]_{anode}}{[Zn^{2+}]_{cathode}} = \dfrac{0.05916}{n}\log\dfrac{[Zn^{2+}]_{cathode}}{[Zn^{2+}]_{anode}}$$

- Electrons flow externally from the dilute-side electrode (anode) to the concentrated-side electrode (cathode).
- This is a galvanic cell (E_cell > 0) even though both electrodes are chemically identical, because dilution/concentration is itself a spontaneous, free-energy-lowering process (entropy of mixing/dilution).

---

## 11. Liquid Junction Potential (LJP) & Potentiometric (Acid–Base) Cells

- **LJP** arises at the boundary between two electrolyte solutions of different concentration/composition, due to **unequal ionic mobilities (transference numbers)** causing unequal diffusion rates across the junction.
- A **salt bridge (||)** minimizes/eliminates LJP by using a highly mobile, nearly equal-mobility electrolyte (e.g., KCl, KNO₃).
- **Cells with transference** (direct liquid–liquid contact) include an LJP contribution to the measured EMF; **cells without transference** (via salt bridge or identical-electrode half-cells) do not.

**Example — H₂ electrode "titration" cell:**
$$Pt,\ H_2(1\,atm)\,|\,HCl(2M,aq)\,||\,HCl(1M,aq)\,|\,H_2(1\,atm),\,Pt$$

- This is a **concentration cell using identical H₂ electrodes** at the same pressure but different HCl (H⁺) concentrations.
- General relation (n = 2 for $2H^+ + 2e^- \to H_2$, but the squared H⁺ term collapses the factor of 2):
$$E_{cell} = \dfrac{0.05916}{2}\log\dfrac{[H^+]^2_{cathode}}{[H^+]^2_{anode}} = 0.05916\,\log\dfrac{[H^+]_{cathode}}{[H^+]_{anode}}$$
- Equivalent to a **pH-based concentration cell**: $E_{cell} = 0.05916\,(\text{pH}_{anode} - \text{pH}_{cathode})$
- **Titrating the left half-cell with KOH:** as OH⁻ neutralizes H⁺ (H⁺ + OH⁻ → H₂O), [H⁺] in that compartment falls, changing E_cell continuously — this is the basis of a **potentiometric acid–base titration**.
- **At the equivalence point:** essentially all original H⁺ is neutralized; if K⁺ is assumed not to alter the electrode's response (spectator-ion assumption), [H⁺] left is governed by water's autoionization/whatever excess remains, and E_cell is recalculated using the new [H⁺].

---

## 12. Thermodynamic Relationships: ΔG° ↔ K ↔ E°

$$\Delta G^{\circ} = -nFE^{\circ} \qquad \Delta G^{\circ} = -RT\ln K \qquad \Delta G^{\circ}=\Delta H^{\circ}-T\Delta S^{\circ}$$

Combining the first two:
$$nFE^{\circ} = RT\ln K \quad\Longrightarrow\quad E^{\circ} = \dfrac{RT}{nF}\ln K \quad\text{or}\quad \log K = \dfrac{nE^{\circ}}{0.05916}$$

> **Key rule:** When combining two half-reactions (e.g., to get a third), **potentials are NOT additive unless n is the same for both** — instead, **add the ΔG° values** (or nE° products), then divide by the new total n to get the resultant E°:
> $$\Delta G^{\circ}_{total} = \Delta G^{\circ}_1 + \Delta G^{\circ}_2, \qquad E^{\circ}_{total} = \dfrac{-\Delta G^{\circ}_{total}}{n_{total}F}$$

---

## 13. Determining Solubility Product (Ksp) from Electrochemical Data

**Method:** Write the dissolution reaction as the sum of two half-reactions (often one from a solid-salt electrode, one from the pure metal electrode); find overall E°, then use:

$$n F E^{\circ} = RT\ln K_{sp} \quad\Longrightarrow\quad K_{sp} = \exp\left(\dfrac{nFE^{\circ}}{RT}\right)$$

**Example logic (AgI):**
$$AgI(s) + e^- \rightarrow Ag(s) + I^- \quad (E^{\circ}_1)$$
$$Ag(s) \rightarrow Ag^+ + e^- \quad (E^{\circ}_2,\ \text{reverse of standard reduction, so sign flips})$$
$$\text{Sum: } AgI(s) \rightarrow Ag^+ + I^- \quad E^{\circ} = E^{\circ}_1 + E^{\circ}_2$$
(Here both half-reactions have the same n = 1, so direct addition of E° values is valid — contrast with §12 where n differs.)

**Alternative method (given Ksp, find a related E°):** Use ΔG° route (§12 rule) — compute $\Delta G^{\circ}_1 = -RT\ln K_{sp}$ for the dissolution/precipitation equilibrium, compute $\Delta G^{\circ}_2 = -nFE^{\circ}$ for the known half-reaction, **add the ΔG° values**, then back-calculate the unknown E° using the *combined* n.

---

## 14. Hess's Law Applied to Solubility (Lattice / Solvation Cycle)

For a salt dissolving: **Solid lattice → gaseous ions → solvated (aqueous) ions**

$$\Delta H_{solution} = \underbrace{-\Delta H_{lattice}}_{\text{break lattice (endothermic)}} + \underbrace{\Delta H_{solvation}}_{\text{solvate ions (exothermic)}}$$

(Note: ΔH_lattice as usually tabulated = *lattice formation* enthalpy, negative; breaking the lattice is the reverse, so its sign flips.)

**Getting ΔH_solution from K and ΔS (via thermodynamic cycle):**
$$\Delta G^{\circ}_{solution} = -RT\ln K \qquad \Delta G^{\circ} = \Delta H_{solution} - T\Delta S_{solution}$$
$$\Rightarrow\ \Delta H_{solution} = \Delta G^{\circ} + T\Delta S_{solution} = -RT\ln K + T\Delta S_{solution}$$

**Then solve for the heat of solvation:**
$$\Delta H_{solvation} = \Delta H_{solution} + \Delta H_{lattice}\ (\text{using the tabulated, formation-sign value})$$

> **Rationalizing low solubility trend (AgCl → AgBr → AgI):** compare the magnitudes/balance of ΔH_lattice (becomes less negative down the group, easier to break) vs. ΔH_solvation and the ΔS_solu contribution to ΔG°, and correlate with the decreasing K (solubility) values.

---

## 15. Solid-State Chemistry — Voids in FCC (Close-Packed) Lattices

- For **N** atoms arranged in an **FCC** lattice:
$$\text{Tetrahedral voids} = 2N \qquad \text{Octahedral voids} = N \qquad \text{Total voids} = 3N$$

**Worked-type calculation:**
$$\text{Occupied Th voids} = (\text{fraction occupied}) \times 2N$$
$$\text{Vacant Th voids} = 2N - \text{Occupied Th voids}$$
$$\%\ \text{of total voids occupied} = \dfrac{\text{Occupied voids}}{\text{Total voids } (3N)}\times 100$$

---

## 16. pH-Dependent Redox Potential (Nernst Equation with H⁺ in Q)

For a proton-coupled redox couple, e.g. quinone/hydroquinone:
$$Q + 2H^+ + 2e^- \rightarrow QH_2 \qquad E^{\circ}$$

$$Q_r = \dfrac{[QH_2]}{[Q][H^+]^2}$$

With **equimolar** oxidized/reduced forms ([QH₂] = [Q]), these cancel, leaving:
$$E = E^{\circ} - \dfrac{0.05916}{2}\log\left(\dfrac{1}{[H^+]^2}\right) = E^{\circ} - \dfrac{0.05916}{2}\times 2\,\text{pH} = E^{\circ} - 0.05916\times\text{pH}$$

- General takeaway: proton-coupled electrode potentials shift with pH — more acidic (lower pH) → higher (more positive) E; more basic → lower E.

---

## 17. Battery Basics — Capacity, Energy, Power, Density

| Quantity | Formula |
|---|---|
| Total capacity | $Q = (\text{specific capacity, mAh/g}) \times (\text{mass, g})$ |
| Total energy | $E = (\text{energy density, Wh/kg}) \times (\text{mass, kg})$ |
| Mass needed for target energy | $m = \dfrac{E_{required}}{\text{energy density}}$ |
| Current for a given C-rate | $I = \dfrac{Q}{t}$ (t = 1 h for 1C; Q from loading × area × specific capacity) |
| Active mass from loading | $m = (\text{loading, mg/cm}^2)\times(\text{electrode area, cm}^2)$ |
| Capacity fade/growth over cycles (arithmetic progression) | $a_n = a_1 + (n-1)d$ (aₙ = specific capacity at cycle n, d = increment/fade per cycle) |
| Capacity at cycle n | $Q_n = a_n \times m$ |
| State of charge (SoC) | $\text{SoC} = \dfrac{\text{Remaining capacity}}{\text{Rated (full) capacity}} \times 100\%$ |

**Key definitions:**
- **Specific capacity:** charge stored per unit mass of active material (mAh/g).
- **Energy density (gravimetric):** energy stored per unit mass (Wh/kg).
- **Power density:** power delivered per unit mass (W/kg) — energy delivered per unit time, normalized by mass.
- **C-rate:** current normalized to fully charge/discharge the rated capacity in 1/C hours (1C = full discharge in 1 h).

---

## Quick-Reference: Core Formula Box

$$C_{dl} = \dfrac{\varepsilon A}{d} \qquad E = E^{\circ}-\dfrac{0.05916}{n}\log Q \qquad E^{\circ}_{cell}=E^{\circ}_{cathode}-E^{\circ}_{anode}$$
$$\Delta G^{\circ}=-nFE^{\circ}=-RT\ln K \qquad \Lambda_m=\dfrac{\kappa}{c} \qquad \alpha=\dfrac{\Lambda_m}{\Lambda_m^{\circ}} \qquad \Lambda_m^{\circ}=\nu_+\lambda_+^{\circ}+\nu_-\lambda_-^{\circ}$$
$$S=\dfrac{\kappa_{salt}}{\Lambda_m^{\circ}} \qquad K_{sp}=\exp\left(\dfrac{nFE^{\circ}}{RT}\right) \qquad \Delta H_{solution}=-\Delta H_{lattice}+\Delta H_{solvation}$$
$$\text{FCC: Tet. voids}=2N,\ \text{Oct. voids}=N \qquad Q=\text{sp.cap}\times m \qquad E_{energy}=\text{energy density}\times m$$

*(Note: structure/discussion of TiCoO₂ intentionally omitted, per request.)*
