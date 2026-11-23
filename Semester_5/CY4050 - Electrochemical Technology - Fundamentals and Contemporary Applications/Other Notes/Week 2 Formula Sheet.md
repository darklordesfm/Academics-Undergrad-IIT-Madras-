# Week 2 — Battery Engineering, Kinetics, pH Sensing & Solid-State Li-ion Chemistry
## Consolidated Formula Sheet & Notes (Week-2 Lecture Notes + Blackboard + Tutorial 4)

---

# PART A — Battery Performance Metrics

## A.1 Capacity, Charge, C-rate
$$1\ Ah = 3600\ C \qquad (\text{since } 1\ A = 1\ C\,s^{-1})$$

- **C-rate:** normalized charge/discharge speed relative to rated capacity.
  - **1C** → full capacity delivered in **1 h**.
  - **0.1C** → full capacity in **10 h**.
  - **5C** → full capacity in **1/5 h = 12 min**.
- Two cells can both be "at 1C" while carrying very different **absolute currents**, since 1C depends on each cell's rated capacity.
  - E.g., 1000 mAh cell: 1C = 1 A, 0.1C = 0.1 A, 5C = 5 A.

## A.2 Energy & Specific Energy
$$E\ (Wh) = Q\ (Ah) \times V\ (V)$$
$$\text{Specific energy (Wh/kg)} = \dfrac{E\ (Wh)}{m\ (kg)}$$

## A.3 Power & Specific Power
$$P\ (W) = I\ (A) \times V\ (V)$$
$$\text{Specific power (W/kg)} = \dfrac{P\ (W)}{m\ (kg)}$$

## A.4 Ragone Plot
- X-axis: specific energy (Wh/kg); Y-axis: specific power (W/kg).
- Diagonal lines = constant discharge time:
$$t \approx \dfrac{E}{P}$$
- High specific energy → long runtime/range. High specific power → rapid delivery (acceleration/bursts). Ideal device sits **upper-right**.

## A.5 Charge–Discharge Curves & Polarization
- Real measured voltage ≠ equilibrium voltage due to kinetic, ohmic, and mass-transport losses (**overpotentials, η**):
$$V_{measured} = V_{equilibrium} \pm \eta_{kinetic} \pm \eta_{ohmic} \pm \eta_{mass\,transport}$$
- Charge voltage > discharge voltage at same SoC → **voltage hysteresis**.

---

# PART B — Electrode–Electrolyte Interfaces

## B.1 Why Interfaces Matter
- Reactions occur at the **electronic conductor (electrode) / ionic conductor (electrolyte)** boundary.
- Near the boundary, force anisotropy rearranges ions/dipoles into a thin **interphase**, producing a large interfacial potential drop over nm/sub-nm distances → very large local electric fields.

## B.2 Electrical Double Layer (capacitor analogy)
$$q = C_{dl}\times E$$
- Typical Cdl ~ tens of μF/cm²; varies with potential and composition (interfacial structure changes).

## B.3 Faradaic vs. Nonfaradaic Processes
- **Faradaic:** involves electron transfer; obeys **Faraday's law** (charge ∝ chemical change).
- **Nonfaradaic:** no net charge transfer across interface (adsorption/desorption, double-layer charging) — still produces external transient currents.

## B.4 Potential as Electron-Energy Control
- More **negative** potential → higher electron energy → favors **reduction** (of species with accessible empty states).
- More **positive** potential → lower electron energy → favors **oxidation**.
- Molecular picture: oxidation = electron removal from **HOMO**; reduction = electron addition to **LUMO**.
- Solid picture: discrete orbitals → bands; relative alignment of occupied/unoccupied bands (or Fermi levels) controls voltage/reaction direction.

---

# PART C — Reaction Kinetics & Electroanalytical Setup (Blackboard, Aug 17–18)

## C.1 Rate Law and Current
For $A \rightarrow B + e^-$:
$$-\dfrac{d[A]}{dt} = k[A] = \dfrac{d[B]}{dt}$$

**Relating rate to measured current:**
$$I = nF\left(-\dfrac{d[A]}{dt}\right) = nFk[A] = nF\dfrac{d[B]}{dt}$$

- Units check: rate $\left(\dfrac{mol}{cm^3\cdot s}\right) \times$ charge/mol $\left(\dfrac{C}{mol}\right) \times$ volume-normalization → current density $\left(\dfrac{A}{cm^2}\right)$ after multiplying by the relevant geometric factor (thickness/area), i.e.
$$\dfrac{C}{mol}\times\dfrac{mol}{cm^3\cdot s}\times 1\times\dfrac{cm^3}{cm^2}\left(=\text{path length}\right) \Rightarrow \dfrac{A}{cm^2}$$

## C.2 Current Density Normalization
$$\dfrac{C}{S\cdot cm^3} \equiv \dfrac{A}{cm^3} \quad\longrightarrow\quad \text{normalized per electrode area: } \dfrac{A}{cm^2}$$

## C.3 Three-Electrode Setup
- **WE (Working Electrode):** electrode of interest, where the reaction under study occurs.
- **RE (Reference Electrode):** fixed, stable potential — no current passes through it; used to *measure* WE potential.
- **CE (Counter/Auxiliary Electrode):** carries the current balancing the WE reaction, protecting RE from current-induced drift.
- Voltmeter (V) reads WE potential relative to RE; current flows between WE and CE.

## C.4 Activation Energy & Energy Diagrams
- Reaction coordinate diagram: reactants (R) → transition state (peak, Ea) → products (P); $\Delta G$ = energy difference between R and P.
- For a two-step/combined barrier process:
$$E_a = E_{a1} + E_{a2}$$
- Relating activation free energy to electrochemical driving force:
$$\Delta G^{\ddagger} = -nF\eta_{act}$$
where η_act is the activation overpotential; and generally $\Delta G = -nFE$ for the overall electrochemical step.

## C.5 Mass-Transport (Diffusion) Limited Current
**Fick's first law form used for flux at an electrode:**
$$J = D\dfrac{dC}{dx} = D\dfrac{[C_b - C_s]}{\Delta x}$$
- $C_b$ = bulk concentration, $C_s$ = surface concentration, D = diffusion coefficient, Δx = diffusion layer thickness.
- As current (J) increases, the surface concentration $C_s$ drops — eventually mass transport becomes rate-limiting (plateau/limiting current).

## C.6 Simple Catalytic Equilibrium
For $A \underset{cat}{\rightleftharpoons} B$:
$$K_{eq} = \dfrac{[B]_{eq}}{[A]_{eq}}$$
- A catalyst changes the **rate** (lowers Ea) but does not change $K_{eq}$ (thermodynamics unaffected).

---

# PART D — pH Measurement: The Glass Membrane Electrode

## D.1 Concept
- A **pH meter is a special voltmeter**: it measures the potential difference (and its changes) across a **thin glass membrane**.
- Electrode construction: internal Ag/AgCl reference (in 0.1 M HCl) inside the glass bulb, external Ag/AgCl reference (in KCl solution) outside, connected via a **permeable porous junction** to the test solution; thin pH-sensitive glass membrane at the tip.

## D.2 Membrane Potential
$$E_{membrane} = E_{inner} - E_{outer} = 0.0592\,\log\dfrac{[H^+]_{inner}}{[H^+]_{outer}}$$

- Glass membrane structure: **dry glass** core (~50 μm) sandwiched between two thin **hydrated gel layers** (~5–100 nm) — one facing the internal filling solution, one facing the test solution. Ion-exchange at the hydrated layers generates the pH-dependent potential.

## D.3 Is the Junction Potential Really Eliminated?
- **No — not perfectly.** Depending on sample ionic strength, composition, and junction design, a **residual liquid-junction potential (LJP)** of a few mV can remain.
- At 25 °C the ideal pH response ≈ **59.16 mV/pH**.
- A residual **3 mV** LJP error ≈ $\dfrac{3}{59.16} \approx 0.05$ **pH units** — significant for precise measurements.

## D.4 How a pH Meter Compensates
- **Calibration with standard buffers** (e.g., pH 4, 7, 10) determines the electrode's **offset and slope**.
- Offset lumps together: reference-electrode potential, glass-membrane asymmetry potential, residual LJP, and small electronic offsets.
- **Limitation:** calibration does not perfectly correct LJP if it *changes* between buffer and a sample of very different ionic composition (**residual liquid-junction error**).
- **Manufacturer mitigation:** use **concentrated KCl** as reference electrolyte; design the junction for a controlled (usually outward) flow through a ceramic/fiber junction — keeps the composition near the junction reproducible.

## D.5 Related Nernstian Half-Cells (Blackboard)
**Hydrogen electrode (reference concept):**
$$2H^+(aq) + 2e^- \rightleftharpoons H_2(g) \qquad E^{\circ} = 0\ V\ \text{vs. SHE}$$
$$E = E^{\circ} - \dfrac{RT}{2F}\ln\dfrac{[H_2]}{[H^+]^2} = E^{\circ} + 0.0592\log[H^+] = E^{\circ} - 0.0592\,\text{pH}$$

**AgCl electrode / solubility (used for reference electrodes):**
$$AgCl(s) \rightleftharpoons Ag^+(aq) + Cl^-(aq) \qquad K_{sp} = [Cl^-][Ag^+]$$
$$AgCl(s) + e^- \rightleftharpoons Ag(s) + Cl^-(aq) \qquad E = E^{\circ} - \dfrac{RT}{F}\ln[Cl^-]$$
- **Saturated KCl** reference electrolyte: $KCl(s) \rightleftharpoons K^+(aq) + Cl^-(aq)$ — fixes $[Cl^-]$, and hence fixes E, at a stable, reproducible value (basis of the standard Ag/AgCl reference electrode).

---

# PART E — Solid-State Crystal Chemistry for Lithium Storage

## E.1 Close-Packing & Void-Counting Rules

| Packing | Stacking | Octahedral voids (for N anions/atoms) | Tetrahedral voids |
|---|---|---|---|
| **HCP** | ABAB… | N | 2N |
| **CCP / FCC** | ABCABC… | N (4 per conventional FCC cell) | 2N (8 per conventional FCC cell) |

- General counting rule: **N close-packed atoms/anions → N octahedral voids + 2N tetrahedral voids** (total 3N voids).
- An FCC (CCP) **unit cell** contains 4 atoms → **4 octahedral + 8 tetrahedral voids per cell**.

## E.2 Polyhedra Connectivity
- Two coordination polyhedra can share a **corner** (1 shared anion), an **edge** (2 shared anions), or a **face** (3 shared anions).
- **Face-sharing** brings the two central cations closest together → greatest cation–cation electrostatic repulsion; requires either reduced effective repulsion or highly polarizable anions to be favorable.
- Two voids sharing a common triangular face (e.g., adjacent Oh/Td pair in a CCP lattice) is the geometric basis of Li⁺ hopping pathways (§E.6).

## E.3 Anion Polarizability: Sulfides vs. Oxides
- **S²⁻** is more polarizable than **O²⁻** (valence electrons in a higher principal shell, more easily distorted).
- Greater polarizability → increased covalent character → can stabilize closer cation approaches (e.g., extensive face-sharing), motifs less favorable in more ionic oxide frameworks.

## E.4 Intercalation / Deintercalation & Defects
- **Intercalation:** insertion of ions into a host lattice without destroying the framework. **Deintercalation:** removal.
- Common defect types on cycling:
  1. **Vacancies** — Li removed from its site.
  2. **Valence (redox) defects** — TM oxidation states adjust to maintain charge neutrality.

## E.5 Case Study — TiS₂ (Early Intercalation Cathode)
- Layered sulfide; Ti in **octahedral** coordination between close-packed S²⁻ layers; weak van der Waals interlayer galleries host Li⁺.
$$TiS_2 + xLi^+ + xe^- \rightarrow Li_xTiS_2 \qquad (\text{coupled to } Ti^{4+}\rightarrow Ti^{3+})$$
- Li occupies **octahedral** LiS₆ sites; these can be **face-sharing** with neighboring TiS₆ octahedra (enabled by sulfide polarizability).
- Insertion causes anisotropic lattice "breathing" — must stay limited for good cycling stability.
- If Ti migrates into interlayer galleries during synthesis, it blocks diffusion pathways → lowers rate capability.

## E.6 Case Study — Graphite Anode
- Stacked graphene layers, weak van der Waals interlayer gap.
- **Practical maximum stoichiometry:** $LiC_6$ (1 Li per 6 C atoms).
- Li insertion increases interlayer spacing (moderate breathing reversible; excessive → exfoliation, capacity fade).
- Li⁺ must enter **largely desolvated** — solvent co-intercalation irreversibly disrupts stacking.

## E.7 Case Study — LiCoO₂ (Layered Oxide, O3 Structure)
- Derived from a **CCP O²⁻ framework**; Li⁺ and Co³⁺ occupy **alternating octahedral layers** (strong ordering due to charge/size mismatch).
- **O3 notation:** "O" = Li resides in **Octahedral** sites; "3" = **three-layer** oxygen stacking repeat period.

**Stacking sequence (from board):**
$$\ldots C\,Co\,A\,Li\,B\,Co\,C\,Li\,A\,Co\,B\,Li\,C\,Co\,A\ldots$$
- Repeat unit → $Li_3Co_3O_6 = LiCoO_2$ (3 Li, 3 Co, 6 O per formula-repeat).
- Unit-cell atom counting uses fractional sharing (corner = 1/6 or 1/3 etc. depending on polyhedron type, edge = 1/2, face/body = full) — e.g. Li: $3 + 6\times\frac13 + 1 + 3 = 9$; similar bookkeeping for Co (9) and O (18) in the extended/hexagonal cell.

**Li⁺ hopping pathway:**
$$\text{Octahedral} \rightarrow \text{Tetrahedral (intermediate)} \rightarrow \text{Octahedral}$$
- Requires distorting a **triangular oxygen window** → energy barrier → contributes to polarization/voltage hysteresis.

**Electronic structure & conductivity:**
- Direct **Co–Co** interaction via shared edges in the Co plane → electronic (metallic-type) conductivity.
- $Li_{1-x}CoO_2$ becomes **metallic** on charging: holes introduced into the **t₂g band** ($t_{2g}^{6-x}$).
- Fast 2D Li⁺ diffusion/conductivity confined within the Li layer.
- **Parallel conduction pathways:** O–Li–O slab = **ionic conductor**; O–TM–O slab = **electronic conductor**. TM–O bonds are covalent; Li–O bonds are more electrostatic.

**Stability limits:**
- $t_{2g}$ band overlaps the top of the O²⁻:2p band beyond **x > 0.5** → **oxygen release** on deep charging → limits **practical capacity to ~140 mAh/g**.
- Increased Co–O covalency with delithiation → **contraction of Co–O distance** → decreases the **c lattice parameter**; this also **shrinks tetrahedral void volume**, **increasing the activation energy for Li⁺ hopping**.
- **Anti-site defects** (TM sitting in the Li layer) obstruct Li diffusion (electrostatic repulsion, detours), lowering C-rate capability.
- Deep delithiation can trigger **oxygen redox** (peroxide-like states) → destabilization.
- **Layer gliding** can cause **O3 → P3** phase transitions — often partially irreversible, consuming cycling energy.
- Chemical delithiation (used to study TM oxidation states):
$$LiMO_2 + xNO_2BF_4 \rightarrow Li_{1-x}MO_2 + xNO_2 + xLiBF_4$$
(NO₂BF₄ acts as chemical oxidant; a series of oxidants of increasing strength vs. NHE — e.g., I₂/I⁻ 0.5 V, Br₂/Br⁻ 1.1 V, NO⁺/NO 1.7 V, NO₂⁺/NO₂ 2.1 V, MoF₆/MoF₆⁻ 2.4 V, PtF₆/PtF₆⁻ 4.4 V — can be used to progressively delithiate and map voltage vs. Li content.)

**Which TMs adopt the O3 (LiMO₂) structure?**

| Sc | Ti | V | Cr | Mn | Fe | Co | Ni | Cu |
|---|---|---|---|---|---|---|---|---|
| No | Yes | Yes | Yes | No | No | Yes | Yes | No |

- LiMnO₂, LiFeO₂ obtained by **ion-exchanging** Na analogues with Li salts (not direct synthesis).
- **V and Mn** undergo **layered → spinel** transition during cycling due to **low octahedral site stabilization energy (OSSE)**; Mn⁴⁺ (small ionic size) migrates easily into tetrahedral sites.
- **LiTiO₂:** operates at only 1.5 V — not a suitable cathode.
- **LiCrO₂:** exhibits large polarization.
- **LiNiO₂:** ordered synthesis is difficult — Ni³⁺ easily reduces to Ni²⁺, forming $Li_{1-y}Ni_{1+y}O_2$ (**Ni "pinning"** of the Li layer, obstructing diffusion).

## E.8 Crystal Field Stabilization Energy (CFSE) and OSSE
- General octahedral CFSE (example, low-spin Co³⁺, d⁶, t₂g⁶eg⁰):
$$CFSE = 6(-0.4\Delta) + 0(0.6\Delta) = -2.4\Delta$$

| TM ion / config. | Octahedral CFSE | Tetrahedral CFSE |
|---|---|---|
| Mn³⁺ / d⁴ | $t_{2g}^3e_g^1$; $-0.6\Delta_0$ | $e_g^2t_{2g}^2$; $-0.18\Delta_0$ |
| Ni³⁺ / d⁷ | $t_{2g}^6e_g^1$; $-1.88\Delta_0$ | $e_g^4t_{2g}^3$; $-0.53\Delta_0$ |
| Co³⁺ / d⁶ | $t_{2g}^6e_g^0$; $-2.4\Delta_0$ | $e_g^3t_{2g}^3$; $-0.27\Delta_0$ |

$$OSSE = (\text{Octahedral CFSE}) - (\text{Tetrahedral CFSE})$$
- **Larger (more negative) OSSE** → stronger preference to remain octahedral → more resistant to migration/layered-to-spinel transition. (Co³⁺ has the largest OSSE magnitude → LiCoO₂ is structurally very stable; Mn³⁺ has the smallest → prone to migration/disproportionation.)

## E.9 Comparing Cathode Chemistries (Band Picture)
- **Cobalt (Co):** reversible, electrochemically stable — but thermally unstable and costly.
- **Manganese (Mn):** thermally stable and cheap — but prone to TM mixing/migration and is comparatively electrochemically "inert" in some configurations.
- Band theory gives the **energies**; the **density of states (DOS)** tells how many electronic states sit at each energy.
- The top of the **S²⁻:3p band** lies at **higher energy** than the top of the **O²⁻:2p band** → sulfide-cathode redox couples sit higher (closer to Li/Li⁺) → **oxide cathodes generally give higher voltage than sulfide cathodes** (bigger energy gap to Li/Li⁺).

## E.10 Increasing Capacity: NMC $\left(LiNi_{1-y-z}Mn_yCo_zO_2\right)$
- During synthesis: $Mn^{3+}\rightarrow Mn^{4+}$; $Ni^{3+}\rightarrow Ni^{2+}$.
- **Mn⁴⁺** acts as a non-redox-active **structural stabilizer**; its band lies above O²⁻:2p → chemical stability without O₂ release — but Mn⁴⁺ can still migrate (octahedral TM-plane site → octahedral Li-plane site via adjacent tetrahedral voids) due to low OSSE, potentially triggering layered→spinel transition.
- **Ni³⁺** has an OSSE **between** Mn³⁺ and Co³⁺; its redox band barely touches the top of O²⁻:2p, allowing oxidation all the way to **Ni⁴⁺** → higher achievable capacity.

## E.11 Operation of a Li-ion Cell (during charging)
$$\text{Cathode: } LiMO_2 \rightarrow Li_{1-n}M_nM_{1-n}O_2 + nLi^+ + ne^-$$
$$\text{Anode: } C_6 + nLi^+ + ne^- \rightarrow Li_nC_6$$
- Components: **Cu foil** current collector (anode side, lithiated graphite), **separator**, **electrolyte**, **Al foil** current collector (cathode side, Li-metal oxide).

---

# PART F — Spinel Structures (LiMn₂O₄ family)

## F.1 Why Layered → Spinel is Structurally "Easy"
- **Common feature:** both layered (LiMO₂) and spinel (LiM₂O₄) structures share a **CCP array of the oxide ion sublattice** — only the cation distribution among Oh/Td sites differs, so interconversion is comparatively facile.

**Phase transition sequence (delithiation of a layered manganate):**
$$LiMnO_2\ (= Li_2Mn_2O_4,\ \text{Layered}) \xrightarrow{-Li^+} LiMn_2O_4\ (\text{Spinel},\ 3\text{–}3.2\ V) \xrightarrow{-Li^+\ (\text{from Td sites})} \square\,Mn_2O_4\ (\sim4.2\ V)$$

- $LiMn_2O_4 = Li_{0.5}MnO_2 = Li_8Mn_{16}O_{32}$ (per conventional 8-formula-unit cell).
- **16d octahedral** sites occupied by Mn; **16c octahedral** sites vacant; **32 sites** for oxygen; **1/8 of tetrahedral sites (8a)** occupied by Li⁺.
- i.e., **8 FCC (oxide) lattices** combine to build one spinel unit cell.

## F.2 Polyhedral Connectivity in Spinel
- **Oh–Oh:** edge-sharing. **Td–Oh:** face-sharing *and* edge-sharing (context-dependent, per connection type).
- Detailed connectivity (filled 8a Td and 16d Oh sites):
  - **8a–16d:** corner-share
  - **8a–16c:** face-share (4 neighboring 16c octahedra around each 8a tetrahedron)
  - **16c–16d:** edge-share
  - **16d–16d:** edge-share
- **Consequence:** Li⁺ insertion/diffusion along the **[111]** direction is **difficult** (TM obstruction); **[100], [010], [001]** directions are favorable/"good choices" for Li⁺ transport.

## F.3 Site Energy Controls Cell Voltage
- Family: $LiMn_2O_4$, $LiTi_2O_4$, $LiV_2O_4$ — all with a **CCP oxide array**; moving from LiCoO₂ → LiMn₂O₄ significantly **reduces cost**.
- $Mn^{3+/4+}$ occupies **16d octahedral** sites; $Li^+$ occupies **8a tetrahedral** sites (reversible intercalation/deintercalation); **16c octahedral sites remain empty** (diffusion pathway: Li hops tetrahedral-site-to-tetrahedral-site *via* the free 16c octahedral sites).
- $Li_{1-x}Mn_2O_4$ operates at **~4 V**, capacity **~130 mAh/g** (1 Li per 2 Mn).
- **Additional** Li⁺ can insert at the empty **16c octahedral** sites at **~3 V** — note the voltage differs even though the **same** $Mn^{3+/4+}$ redox couple is involved (voltage depends on **site energy**, not just the redox couple identity).
- **Critical stability issue — Mn disproportionation:**
$$2Mn^{3+} \rightarrow Mn^{4+} + Mn^{2+}$$
  - Occurs even with trace H⁺ present; **Mn⁴⁺ stays in the structure**, but **Mn²⁺ dissolves into the electrolyte** and contaminates the anode.
- $LiTi_2O_4$ gives only **1.5 V**; $LiV_2O_4$ suffers structural change and low **~3 V** voltage — both less attractive than LiMn₂O₄.
- Attempts to make $LiCo_2O_4$, $LiNi_2O_4$ (chemically extracting 50% Li, calcining) **did not work** — lost oxygen during synthesis.

## F.4 High-Voltage Spinel Oxides: $LiMn_{1.5}Ni_{0.5}O_4$
- **CCP array** of oxide ions.
- **Mn exists as Mn⁴⁺** (redox energy of $Mn^{4+}$ $t_{2g}$ lies *below* $Ni^{2+/3+}$) — Mn stays electrochemically "spectator."
- **Ni exists as Ni²⁺** initially.
- $Ni^{2+/3+}$ and $Ni^{3+/4+}$ couples drive Li⁺ insertion/deinsertion at tetrahedral sites → **~4.7 V battery**.
- Capacity **~135 mAh/g**; difficult to maintain due to lack of a suitably stable electrolyte at this high voltage.
- **Overall volume change < 2%** — why so small?
  - Redox is mainly $Ni^{2+}/Ni^{4+}$; **Mn stays ~Mn⁴⁺** (Jahn–Teller **inactive**, d³) → no large Jahn–Teller distortions.
  - The spinel oxygen framework stays intact — essentially **tightening TM–O bonds** as Ni is oxidized, rather than restructuring.

## F.5 Zero-Strain Material: $Li_4Ti_5O_{12}$ ("Structural Chameleon")
- Excursion between **spinel** and **rock-salt** structures; enables **high C-rate** and **exceptional cycle life**.

**Interstitial-site occupancy comparison (CCP anion arrangement):**

| Anion Arrangement | T⁺ | T⁻ | Oh | Example |
|---|---|---|---|---|
| CCP | – | – | 1 | NaCl (rock salt) |
| CCP | 1 | – | – | ZnS (blende) |
| CCP | 1/8 → 0.5 | 1/8 → 0.5 | 1/2 | MgAl₂O₄ (Spinel) |
| CCP | – | – | 1/2 | CdCl₂ |
| CCP | – | – | 1/3 | CrCl₃ |
| CCP | 1 | 1 | – | K₂O (antifluorite) |
| CCP (BaO₃ layers) | – | – | 1/4 | BaTiO₃ (Perovskite) |
| ReO₃ (with 1/4 O vacancy) | – | – | 1/4 | (Ba site vacant in Perovskite) |

**Deriving the formula:**
$$3\times AB_2O_4 = A_3B_6O_{12} = A_3BB_5O_{12} = Li_3(Li)Ti_5O_{12}$$
$$Li_3(Li)Ti_5O_{12} + 3Li^+ + 3e^- \rightarrow Li_7Ti_5O_{12}$$

- Tetrahedrally coordinated ions (8a sites) shown conventionally as: $[Li_3]_{8a}[LiTi_5]_{16d}[O_{12}]_{32e}$
- On lithiation → $[Li_6]_{16c}[LiTi_3^{3+}Ti_2^{4+}]_{16d}[O_{12}]_{32e}$ — **this is essentially the NaCl (rock-salt) structure**: entire tetrahedral holes become unoccupied.
- **Consequence: no significant volume change → nearly perfect cycling reversibility.**
- Reported **volume change: ~0.2–0.3%**.
- Since Ti is already in the **4+** state within the fully-lithiated structure, **Li cannot be further removed** from this structure (limits it as an anode/low-voltage insertion material, not further extractable).

---

# PART G — Voltage, Energy-Level Alignment, & Electrolyte Stability

## G.1 Voltage as a Free-Energy Difference
$$\Delta G = -nFE$$
- Electrons flow spontaneously from **higher-energy states in the anode** to **lower-energy accepting states in the cathode**; larger energy gap → higher voltage.
- Oxide cathodes typically give **higher voltage** than sulfide cathodes because oxide-derived electronic states generally sit **lower in energy** → larger gap relative to Li.

## G.2 Choosing Anodes & Cathodes (Qualitative)
- Anode materials with potential **close to Li/Li⁺** (very low vs. Li) maximize cell voltage.
  - **Graphite:** close to Li, high energy density, but needs stable SEI/electrolyte compatibility.
  - **Li₄Ti₅O₁₂ (LTO):** higher potential vs. Li/Li⁺ → lower cell voltage, but improves safety and suppresses Li plating.
- Cathodes should stabilize **higher TM oxidation states** while maintaining structural integrity/reversibility.
  - **Layered oxides** (e.g., LiCoO₂): high voltage, but stability limits at high delithiation.
  - **Polyanion frameworks** (e.g., LiFePO₄): trade some voltage for enhanced safety/thermal stability.

## G.3 Electrolyte Stability Window
- Electrolyte must remain stable across the full cell operating voltage range; oxidation at cathode or reduction at anode causes decomposition (cell failure) unless a protective interphase forms.
- **Water is unsuitable** for typical Li-ion voltages: small thermodynamic stability window, and Li reacts strongly with water.
- Hence **non-aqueous organic solvents** are used, typically as mixtures balancing viscosity, dielectric response, donor ability, and film-forming behavior.

---

# PART H — Solvation, Conductivity & Interfacial Kinetics

## H.1 Conductivity: Concentration and Mobility
- High ionic conductivity requires **both**: (i) sufficient concentration of dissociated (charge-carrying) ions, and (ii) sufficient ion mobility.
- More dissolved salt doesn't guarantee higher conductivity — if mobility drops sharply (e.g., ion pairing, viscosity increase), conductivity can *fall*.

$$\kappa \propto \sum_i c_i\,|z_i|\,u_i$$
where $c_i$ = concentration of ion i, $z_i$ = its charge number, $u_i$ = its mobility.

---

# PART I — Tutorial 4 Worked-Problem Theory

## I.1 Spinel Density Calculations (LiMn₂O₄-type)
- **Void counting from FCC oxide sublattice:** if the unit cell contains **Z** O²⁻ ions (e.g., 32),
$$\text{Tetrahedral voids} = 2Z \qquad \text{Octahedral voids} = Z$$
- **Fractional occupancy:**
$$\%\ \text{occupancy of a void type} = \dfrac{\text{ions occupying that void type}}{\text{total voids of that type}}\times100$$
- **Density formula (unit cell method):**
$$\rho = \dfrac{Z_{f.u.}\,M}{N_A\,a^3}$$
where $Z_{f.u.}$ = number of **formula units** per unit cell, M = molar mass (g/mol), $N_A$ = Avogadro's number, $a^3$ = unit cell volume (cm³, with a in cm).
- **Delithiation effect on density:** if the framework (and hence $a$) is treated as rigid/unchanged upon partial Li removal, only **M** changes (Li content reduces M), so density recalculates using the same $a^3$ but the new (lower) formula mass.

## I.2 Quinhydrone Electrode as a pH Sensor
- Quinhydrone = equimolar complex of quinone (Q) and hydroquinone (QH₂):
$$Q + 2H^+ + 2e^- \rightarrow QH_2 \qquad E^{\circ} = 0.699\ V\ (298\ K)$$
- Since $[Q]=[QH_2]$ (equimolar by definition), the Nernst equation simplifies:
$$E_{Q/QH_2} = E^{\circ} - \dfrac{0.0592}{2}\log\dfrac{[QH_2]}{[Q][H^+]^2} = E^{\circ} - \dfrac{0.0592}{2}\log\dfrac{1}{[H^+]^2} = E^{\circ} - 0.0592\times\text{pH}$$
- **Linear dependence on pH only** — this is the basis of using it as a pH sensor.
- When measured against a reference electrode (e.g., SCE, $E_{SCE}=0.242\ V$, constant):
$$E_{cell} = E_{Q/QH_2} - E_{SCE}$$
Rearranged to solve unknown pH: $E_{Q/QH_2} = E_{cell}+E_{SCE}$, then $\text{pH} = \dfrac{E^{\circ}-E_{Q/QH_2}}{0.0592}$.

## I.3 Fuel Cell (H₂–O₂) Calculations
$$H_2(g) + \tfrac12 O_2(g) \rightarrow H_2O(l) \qquad E^{\circ}_{cell}=1.23\ V\ (298\ K),\quad n=2$$

**Thermodynamics:**
$$\Delta G^{\circ} = -nFE^{\circ}$$
(large negative value confirms spontaneity — the reason a fuel cell can deliver continuous electrical work as long as fuel is supplied, unlike a battery with a fixed reactant inventory).

**Current for a required power output:**
$$P = VI \quad\Rightarrow\quad I = \dfrac{P}{V}$$

**Fuel consumption rate:**
$$Q = I\times t \qquad n_e = \dfrac{Q}{F} \qquad n_{H_2} = \dfrac{n_e}{2}\ (\text{since }H_2\to 2H^++2e^-) \qquad \text{mass} = n_{H_2}\times M_{H_2}$$

## I.4 Potentiometric Concentration-Cell / Titration Recap
$$E_{cell} = E_{RHS}-E_{LHS} = \dfrac{RT}{nF}\ln\dfrac{[\,]_{RHS}}{[\,]_{LHS}}$$
- For a simple ratio (e.g., factor of 2 dilution/concentration difference, n=1): $E_{cell}=0.059\log(0.5)= -0.0177\ V$ (sign indicates direction of spontaneous reaction).
- For an H₂-electrode pH cell at neutralization end-point (pH = 7 both sides consistent with water, per the earlier acid–base titration setup):
$$E_{cell}=0.059\times\text{pH} \quad\Rightarrow\quad E_{cell}=0.059\times7=0.413\ V$$

## I.5 Hess's Law: Solubility, Lattice Enthalpy & Solvation (AgCl, AgBr, AgI)
**Dissolution equilibrium:**
$$MX(s) \rightarrow M^+(aq) + X^-(aq) \qquad K = [M^+][X^-] = \exp\left(-\dfrac{\Delta G_{soln}}{RT}\right)$$
$$\Delta G_{soln} = -RT\ln K$$

**Split into enthalpy/entropy:**
$$\Delta G_{soln} = \Delta H_{soln} - T\Delta S_{soln} \quad\Longrightarrow\quad \Delta H_{soln} = \Delta G_{soln} + T\Delta S_{soln}$$

**Relating to lattice & solvation enthalpy** (heat of sublimation $L_{sub} = -\Delta H_{lattice}$):
$$\Delta H_{s,\,salt}\ (\text{heat of solvation}) = \Delta H_{soln} + \Delta H_{lattice}$$

**Worked values (298 K):**

| | AgCl | AgBr | AgI |
|---|---|---|---|
| K (Ksp) | $1.77\times10^{-10}$ | $7.7\times10^{-13}$ | $1.5\times10^{-16}$ |
| $\Delta S_{soln}$ (J mol⁻¹K⁻¹) | 32.98 | 51.34 | 73.59 |
| $\Delta H_{lattice}$ (kJ/mol) | −912 | −900 | −886 |
| $\Delta G_{soln}$ (kJ/mol) | 55.61 | 69.10 | 90.27 |
| $\Delta H_{soln}$ (kJ/mol) | 65.44 | 84.40 | 112.20 |
| $\Delta H_{s,\,salt}$ (kJ/mol) | −846.5 | −815.6 | −773.8 |

- **Interpretation:** AgI is the most insoluble of the three — the (positive) entropy change is **not large enough** to overcome the unfavorable enthalpy balance and make dissolution thermodynamically favorable, despite its less negative lattice enthalpy (easier to break) being partly offset by a much less exothermic solvation step.

---

# Quick-Reference Formula Box

$$1\,Ah=3600\,C \quad E(Wh)=Q(Ah)\times V \quad P=IV \quad t\approx E/P$$
$$q=C_{dl}E \quad I=nFk[A] \quad J=D\dfrac{C_b-C_s}{\Delta x} \quad \Delta G^{\ddagger}=-nF\eta_{act}$$
$$E_{membrane}=0.0592\log\dfrac{[H^+]_{in}}{[H^+]_{out}} \quad E=E^{\circ}-0.0592\,\text{pH (2H}^+\text{/H}_2)$$
$$\text{FCC/CCP: Oct voids}=N,\ \text{Tet voids}=2N\ (\text{per N anions}) \quad \rho=\dfrac{Z_{f.u.}M}{N_Aa^3}$$
$$\Delta G=-nFE \quad \kappa\propto\Sigma c_i|z_i|u_i \quad OSSE=CFSE_{oct}-CFSE_{tet}$$
$$K=\exp(-\Delta G_{soln}/RT) \quad \Delta H_{soln}=\Delta G_{soln}+T\Delta S_{soln} \quad \Delta H_{solvation}=\Delta H_{soln}+\Delta H_{lattice}$$
