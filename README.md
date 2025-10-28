# NOM DE L'ÉLÈVE - KOUANDA YUAN DIETRICH GR:01


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

# Question 2 : Options de développement possible 

- Base de données + API

Une solution plus adaptée pour gérer une très grande bibliothèque serait d’utiliser une base de données au lieu de simples fichiers texte. Actuellement, le programme enregistre les livres et les utilisateurs dans des fichiers, mais cette méthode est difficile à maintenir quand il y a beaucoup d’informations. Une base de données comme SQLite (local) ou tous autres bases de données en ligne permettraient de stocker, classer et retrouver rapidement des millions de livres. Grâce à elle, on pourrait retrouver un livre rapidemement via des index même dans une grande collection et éviter les doublons ou les erreurs (comme prêter le même livre à deux personnes en même temps) nottamment à partir de contraintes et de transactions sécurisées.
Pour que le programme C++ puisse communiquer avec cette base, on pourrait créer une API (une sorte de “pont” entre le C++ et la base). Cette API pourrait être développée dans un autre langage plus adapté à la gestion web, comme Python par exemple. Le programme C++ enverrait des requêtes à l’API (par exemple pour ajouter, supprimer ou chercher un livre) et recevrait les résultats sous forme de JSON. Cela veut dire qu’on ne change pas le menu ni la façon d’utiliser le programme C++ mais on change seulement la manière dont les données sont gérées. Si un jour la bibliothèque d’Alexandrie contient des millions de livres, la base de données pourra être hébergée sur un serveur distant (ou dans le cloud) pour permettre à plusieurs utilisateurs de l’utiliser en même temps, depuis différents ordinateurs ou même une application mobile. On pourrait aussi ajouter un moteur de recherche intelligent (comme pour proposer une recherche plus rapide, avec autocomplétion). Donc, C++ va gérer l’interface, API pour la communication (base + interface) et base de données pour le stockage. Cela rendrait le projet plus solide, prêt à évoluer et capable de gérer des millions de livres et d’utilisateurs.

# NOM DE L'ÉLÈVE - KOUANDA YUAN DIETRICH GR:01





