#include <stdio.h>
#include <string.h>

typedef struct {
    int atomicNumber;
    char symbol[4];
    char name[20];
    double atomicWeight;
} Element;

void displayElement(Element e) {
    printf("\n");
    printf("Atomic Number: %d\n", e.atomicNumber);
    printf("Symbol       : %s\n", e.symbol);
    printf("Name         : %s\n", e.name);
    printf("Atomic Weight: %.4f\n", e.atomicWeight);
    printf("--------------------------------------\n");
}

void displayPeriodicTable(Element elements[], int size) {
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    printf("Modern Periodic Table (compact view):\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%-3d %-3s  ", elements[i].atomicNumber, elements[i].symbol);
        if ((i + 1) % 10 == 0) { 
            printf("\n");
        }
    }
    printf("\n-----------------------------------------------------------------\n");
}

int main() {
    Element periodicTable[] = {
        {1, "H", "Hydrogen", 1.008}, {2, "He", "Helium", 4.0026},
        {3, "Li", "Lithium", 6.94}, {4, "Be", "Beryllium", 9.0122},
        {5, "B", "Boron", 10.81}, {6, "C", "Carbon", 12.011},
        {7, "N", "Nitrogen", 14.007}, {8, "O", "Oxygen", 15.999},
        {9, "F", "Fluorine", 18.998}, {10, "Ne", "Neon", 20.180},
        {11, "Na", "Sodium", 22.990}, {12, "Mg", "Magnesium", 24.305},
        {13, "Al", "Aluminum", 26.982}, {14, "Si", "Silicon", 28.085},
        {15, "P", "Phosphorus", 30.974}, {16, "S", "Sulfur", 32.06},
        {17, "Cl", "Chlorine", 35.45}, {18, "Ar", "Argon", 39.948},
        {19, "K", "Potassium", 39.098}, {20, "Ca", "Calcium", 40.078},
        {21, "Sc", "Scandium", 44.956}, {22, "Ti", "Titanium", 47.867},
        {23, "V", "Vanadium", 50.942}, {24, "Cr", "Chromium", 51.996},
        {25, "Mn", "Manganese", 54.938}, {26, "Fe", "Iron", 55.845},
        {27, "Co", "Cobalt", 58.933}, {28, "Ni", "Nickel", 58.693},
        {29, "Cu", "Copper", 63.546}, {30, "Zn", "Zinc", 65.38},
        {31, "Ga", "Gallium", 69.723}, {32, "Ge", "Germanium", 72.63},
        {33, "As", "Arsenic", 74.922}, {34, "Se", "Selenium", 78.971},
        {35, "Br", "Bromine", 79.904}, {36, "Kr", "Krypton", 83.798},
        {37, "Rb", "Rubidium", 85.468}, {38, "Sr", "Strontium", 87.62},
        {39, "Y", "Yttrium", 88.906}, {40, "Zr", "Zirconium", 91.224},
        {41, "Nb", "Niobium", 92.906}, {42, "Mo", "Molybdenum", 95.95},
        {43, "Tc", "Technetium", 98.0}, {44, "Ru", "Ruthenium", 101.07},
        {45, "Rh", "Rhodium", 102.91}, {46, "Pd", "Palladium", 106.42},
        {47, "Ag", "Silver", 107.87}, {48, "Cd", "Cadmium", 112.41},
        {49, "In", "Indium", 114.82}, {50, "Sn", "Tin", 118.71},
        {51, "Sb", "Antimony", 121.76}, {52, "Te", "Tellurium", 127.6},
        {53, "I", "Iodine", 126.9}, {54, "Xe", "Xenon", 131.29},
        {55, "Cs", "Cesium", 132.91}, {56, "Ba", "Barium", 137.33},
        {57, "La", "Lanthanum", 138.91}, {58, "Ce", "Cerium", 140.12},
        {59, "Pr", "Praseodymium", 140.91}, {60, "Nd", "Neodymium", 144.24},
        {61, "Pm", "Promethium", 145.0}, {62, "Sm", "Samarium", 150.36},
        {63, "Eu", "Europium", 151.96}, {64, "Gd", "Gadolinium", 157.25},
        {65, "Tb", "Terbium", 158.93}, {66, "Dy", "Dysprosium", 162.5},
        {67, "Ho", "Holmium", 164.93}, {68, "Er", "Erbium", 167.26},
        {69, "Tm", "Thulium", 168.93}, {70, "Yb", "Ytterbium", 173.04},
        {71, "Lu", "Lutetium", 174.97}, {72, "Hf", "Hafnium", 178.49},
        {73, "Ta", "Tantalum", 180.95}, {74, "W", "Tungsten", 183.84},
        {75, "Re", "Rhenium", 186.21}, {76, "Os", "Osmium", 190.23},
        {77, "Ir", "Iridium", 192.22}, {78, "Pt", "Platinum", 195.08},
        {79, "Au", "Gold", 196.97}, {80, "Hg", "Mercury", 200.59},
        {81, "Tl", "Thallium", 204.38}, {82, "Pb", "Lead", 207.2},
        {83, "Bi", "Bismuth", 208.98}, {84, "Po", "Polonium", 209.0},
        {85, "At", "Astatine", 210.0}, {86, "Rn", "Radon", 222.0},
        {87, "Fr", "Francium", 223.0}, {88, "Ra", "Radium", 226.0},
        {89, "Ac", "Actinium", 227.0}, {90, "Th", "Thorium", 232.04},
        {91, "Pa", "Protactinium", 231.04}, {92, "U", "Uranium", 238.03},
        {93, "Np", "Neptunium", 237.0}, {94, "Pu", "Plutonium", 244.0},
        {95, "Am", "Americium", 243.0}, {96, "Cm", "Curium", 247.0},
        {97, "Bk", "Berkelium", 247.0}, {98, "Cf", "Californium", 251.0},
        {99, "Es", "Einsteinium", 252.0}, {100, "Fm", "Fermium", 257.0},
        {101, "Md", "Mendelevium", 258.0}, {102, "No", "Nobelium", 259.0},
        {103, "Lr", "Lawrencium", 262.0}, {104, "Rf", "Rutherfordium", 267.0},
        {105, "Db", "Dubnium", 270.0}, {106, "Sg", "Seaborgium", 271.0},
        {107, "Bh", "Bohrium", 274.0}, {108, "Hs", "Hassium", 277.0},
        {109, "Mt", "Meitnerium", 278.0}, {110, "Ds", "Darmstadtium", 281.0},
        {111, "Rg", "Roentgenium", 282.0}, {112, "Cn", "Copernicium", 285.0},
        {113, "Nh", "Nihonium", 286.0}, {114, "Fl", "Flerovium", 289.0},
        {115, "Mc", "Moscovium", 290.0}, {116, "Lv", "Livermorium", 293.0},
        {117, "Ts", "Tennessine", 294.0}, {118, "Og", "Oganesson", 294.0},
    };

    int numElements = sizeof(periodicTable) / sizeof(periodicTable[0]);

    displayPeriodicTable(periodicTable, numElements);

    int choice;
    printf("Enter the atomic number of an element to see details (or 0 to exit): ");
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice > 0 && choice <= numElements) {
            displayElement(periodicTable[choice - 1]);
        } else {
            printf("Invalid atomic number. Please try again.\n");
        }
        printf("Enter another atomic number (or 0 to exit): ");
        scanf("%d", &choice);
    }

    printf("Thank you for exploring the periodic table!\n");
    return 0;
}
