#include "push_swap.h"
/*◦ La pile a contient une quantité aléatoire de négatif et/ou des nombres positifs
qui ne peuvent pas être dupliqués.
◦ La pile b est vide.
• Si aucun paramètre n’est spécifié, le programme ne doit rien afficher et rendre
l’invite de commande
En cas d’erreur, vous devez afficher "Error" suivi d’un ’\n’ sur la sortie d’erreur.
Par exemple, si certains paramètres ne sont pas des nombres, ne tiennent pas dans
un int, ou encore, s’il y a des doublons.*/

void error(void)
{
    write(2, "Error\n", 6);
}

    /*if (argc > 1)
    {
        if (argc == 2)
        //gérer si il n'y que 2 arguments
        if (argc > 2)
        //gérer si il y'en a plus
    }*/