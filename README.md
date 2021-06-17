# wsl
Testing Windows Subsystem For Linux v2

file_menu.c
-----------

Demonstrates an issue with Motif menus in WSLg whereby menu items cannot be selected.  To build the example, use the following command line:

gcc -g file_menu.c -lXm -lXt -o file_menu

hello_dialog.c
-----------

Demonstrates an issue where a 5 second delay occurs opening Xt dialogs.  To build the example, use the following command line:

gcc -g hello_dialog.c -lXm -lXt -o hello_dialog
