# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make 
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Question 1 : Explication d'une notion dans le code qui n'a pas été vu en cours

- Les pointeurs intelligents (std::unique_ptr) - utilisé dans library.cpp et library.h

Les mots-clés new et delete sont utiliés pour créer et détruire des objets manuellement. Par exemple, quand on fait Book* b = new Book(); Cela réserve de la mémoire pour le livre. Mais ensuite, il faut absolument penser à écrire delete b; pour libérer cette mémoire, sinon le programme gardait cette place en mémoire inutilement, ce qu’on appelle une fuite de mémoire. Les pointeurs intelligents comme std::unique_ptr aident à éviter ce problème. Ils gèrent la mémoire automatiquement. Dès qu’un pointeur n’est plus utilisé, la mémoire de l’objet qu’il contient est libérée sans qu’on ait besoin de le faire soi-même. Cela empêche d’oublier de libérer la mémoire. En résumé, new et delete demandent de tout gérer manuellement, tandis que les pointeurs intelligents s’en occupent tout seuls.

* Exemple avec new et delete :                                    

// Déclaration de pointeur vers un objet de type Book  
Book* livre = new Book("Petite ville");                          
...
delete livre;

* Exemple avec std::unique_ptr :

// Création objet de type Book où la gestion est confié à std::unique_ptr
std::unique_ptr<Book> livre(new Book("Petite ville"));



