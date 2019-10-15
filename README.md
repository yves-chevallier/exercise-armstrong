# Nombres narcissiques

- **Durée**: 2 périodes + travail à la maison
- **Date de rendu**: Dimanche soir avant minuit

Un nombre Narcissique ou nombre d'Armstrong est un nombre qui est égal à la somme de ses chiffres chacun exprimé à la puissnce du nombre de chiffres que comporte ce nombre.

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/5bdd2cd01bccf25cd2e26563fa08e1469fc22c05)

Par exemple:

- 9 est un nombre narcissique car `9 == pow(9, 1)`
- 10 n'est **pas** un nombre narcissique car `10 != pow(1, 2) + pow(0, 2)`
- 153 est un nombre d'armstrong car: `153 = pow(1, 3) + pow(5, 3) + pow(3, 3)`
- 154 n'est **pas** un nombre narcissique car: `154 != pow(1, 3) + pow(5, 3) + pow(4, 3)`

Le programme retourne le résultat sur son status de sortie:

- `0` Si le nombre d'entrée est un nombre narcissique
- `1` Si le nombre n'est pas un nombre narcissique
- `255` En cas d'erreur

```shell
$ ./armstrong 153
$ echo $?
0
```

## Objectifs pédagogiques

Ce travail pratique permet de se familiariser avec les notions suivantes:

- Les structures de données (`while`)
- La capture d'arguments (`argv`) et de l'entrée standard (`stdin`)
- Les options d'appel
- L'algorithmique

## Algorihme

Avant de commencer à coder, il vous est demandé d'inclure à votre référentiel un diagramme en flux représentant votre algorithme. Il vous est proposé d'utiliser https://draw.io et d'exporter votre diagramme en un fichier XML que vous pouvez inclure à votre Git.

## Version

Le programme doit afficher son nom et sa version si appelé avec `--version`

```shell
$./armstrong --version
Version 1.0.0 (c)2019 Nom Prenom <firstname.lastname@heig-vd.ch>
```

Le programme de test vérifie la présence du mot `Version` suivi de 3 chiffres séparés par des points e.g `0.1.1`. Il vérifie la présence d'un e-mail exprimé entre `<>`.

## Verbose

Le programme peut être verbeux, c'est à dire afficher le résultat sous forme de texte:

```shell
$./armstrong --verbose 153
Le nombre 153 est bien un nombre d'Armstrong
```

Le programme de test vérifie que le nombre d'entrée est répété sur la sortie, ici `153` et que le texte de sortie comporte `est` ou `is` dans le car ou c'est un nombre narcissique et `n'est pas` ou `is not` ou `isn't` dans le cas inverse.

## Entrée standard

Dans le cas ou le premier argument n'est pas un nombre, le programme obtient le nombre d'entrée via `stdin`:

```shell
$ echo 9 | ./armstrong
$ echo $?
0
```

L'entrée standard peut être lue avec la fonction `scanf`. Essayez par exemple:

```c
int main(void) {
    int number = 0;
    int n = scanf("%d", &number);

    printf("n = %d, number = %d\n", n, number);
}
```
