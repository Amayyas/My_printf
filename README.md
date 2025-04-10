# My_printf

## Description
`My_printf` est une implémentation personnalisée de la fonction standard C `printf()`. Ce projet reproduit les fonctionnalités principales de `printf` avec support pour les spécificateurs de format, les drapeaux, la largeur de champ, la précision et les modificateurs de longueur.

## Fonctionnalités

### Spécificateurs de format supportés
- `%d`, `%i` : Entier signé décimal
- `%u` : Entier non-signé décimal
- `%o` : Entier octal
- `%x`, `%X` : Entier hexadécimal (minuscule/majuscule)
- `%f`, `%F` : Nombre à virgule flottante
- `%c` : Caractère
- `%s` : Chaîne de caractères
- `%p` : Pointeur
- `%b` : Entier binaire
- `%%` : Caractère pourcentage

### Drapeaux supportés
- `-` : Alignement à gauche
- `+` : Force l'affichage du signe pour les nombres positifs
- ` ` (espace) : Insère un espace pour les nombres positifs
- `0` : Remplissage avec des zéros (au lieu d'espaces)
- `#` : Format alternatif (préfixes pour octal et hexa)

### Largeur de champ et précision
- Largeur minimale du champ
- `.n` : Précision
- `*` : Largeur/précision dynamique spécifiée par un argument

### Modificateurs de longueur
- `h` : Short (court)
- `l` : Long
- `ll` : Long Long

## Structure du projet
```
My_printf/
├── include/
│   └── my.h                  # En-têtes pour toutes les fonctions
├── lib/
│   └── my/                   # Bibliothèque implementant my_printf
│       ├── my_printf.c       # Fonction principale
│       ├── my_format_*.c     # Traitement des formats
│       ├── my_formatting*.c  # Formatage de sortie
│       ├── my_put_*.c        # Fonctions d'affichage spécifiques
│       └── ...               # Autres fonctions utilitaires
├── tests/
│   ├── test_basic_format.c   # Tests des formats de base
│   ├── test_format_combinations.c # Tests des combinaisons de drapeaux
│   ├── test_dynamic_formats.c # Tests des formats dynamiques
│   ├── test_edge_cases.c     # Tests des cas limites
│   └── ...                   # Autres tests spécifiques
└── Makefile                  # Compilation du projet
```

## Compilation

Pour compiler la bibliothèque:
```bash
make
```

Pour exécuter les tests:
```bash
make tests_run
```

Pour générer un rapport de couverture HTML:
```bash
make web_tests_run
```

Pour nettoyer les fichiers compilés:
```bash
make fclean
```

## Utilisation

### Exemple de base
```c
#include "my.h"

int main(void)
{
  my_printf("Hello, %s!\n", "world");
  my_printf("Number: %d\n", 42);
  my_printf("Hex: %#x\n", 255);
  my_printf("Float: %.2f\n", 3.14159);
  return 0;
}
```

#### Sortie attendue
```
Hello, world!
Number: 42
Hex: 0xff
Float: 3.14
```

### Compilation avec la bibliothèque
```bash
make compile
```

## Spécificités d'implémentation

### Gestion des formats
La fonction parse les formats en analysant chaque caractère après le `%` pour déterminer:
1. Les drapeaux (`-`, `+`, etc.)
2. La largeur de champ (nombre ou `*`)
3. La précision (`.` suivi d'un nombre ou `*`)
4. Les modificateurs de longueur (`h`, `l`, etc.)
5. Le spécificateur de format (`d`, `s`, etc.)

### Structure de données
Les informations de format sont stockées dans une structure `element_t` qui centralise toutes les options de formatage pour chaque spécificateur.

### Tests
Le projet est entièrement testé avec Criterion, couvrant:
- Formats de base
- Combinaisons de drapeaux et formatage
- Cas limites
- Formats dynamiques
- Modificateurs de longueur
