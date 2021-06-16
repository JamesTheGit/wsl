/* file_menu.c −− demonstrate how to create a menu bar and pulldown
* menu using the Motif creation routines.
*/
#include <Xm/RowColumn.h>
#include <Xm/MainW.h>
#include <Xm/CascadeB.h>
#include <Xm/SeparatoG.h>
#include <Xm/PushBG.h>

#include <stdio.h>
#include <stdlib.h>

static void menu_callback(Widget w, XtPointer client_data, XtPointer call_data);

int main(int argc, char *argv[])
{
    Widget toplevel, MainWindow, MenuBar, FilePullDown;
    Widget openItem, saveItem, exitItem;
    XmString label_str;
    XtAppContext app;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos", NULL, 0, &argc, argv, NULL, NULL);
    MainWindow = XtVaCreateManagedWidget ("main_w", xmMainWindowWidgetClass, toplevel, XmNscrollingPolicy, XmAUTOMATIC, NULL);
    MenuBar = XmCreateMenuBar (MainWindow, "MenuBar", NULL, 0);

    /* create the "File" Menu */
    FilePullDown = XmCreatePulldownMenu (MenuBar, "FilePullDown", NULL, 0);

    /* create the "File" button (attach Menu via XmNsubMenuId) */
    label_str = XmStringCreateLocalized ("File");
    XtVaCreateManagedWidget ("File", xmCascadeButtonWidgetClass, MenuBar, XmNlabelString, label_str, XmNmnemonic, 'F', XmNsubMenuId, FilePullDown, NULL);
    XmStringFree (label_str);

    /* Now add the menu items */
    openItem = XtVaCreateManagedWidget ("Open", xmPushButtonGadgetClass, FilePullDown, NULL);
    XtAddCallback(openItem,XmNactivateCallback,menu_callback,"open");
    saveItem = XtVaCreateManagedWidget ("Save", xmPushButtonGadgetClass, FilePullDown, NULL);
    XtAddCallback(saveItem,XmNactivateCallback,menu_callback,"save");
    XtVaCreateManagedWidget ("separator",xmSeparatorGadgetClass, FilePullDown, NULL);
    exitItem = XtVaCreateManagedWidget ("Exit", xmPushButtonGadgetClass, FilePullDown, NULL);
    XtAddCallback(exitItem,XmNactivateCallback,menu_callback,"exit");
    XtManageChild (MenuBar);

    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}

static void menu_callback(Widget w, XtPointer client_data, XtPointer call_data)
{
    if (strcmp(client_data,"open")==0) {
      printf("Open called\n");
    } else if (strcmp(client_data,"save")==0) {
      printf("Save called\n");
    } else if (strcmp(client_data,"exit")==0) {
      printf("Exit called\n");
      exit(0);
    }
}
