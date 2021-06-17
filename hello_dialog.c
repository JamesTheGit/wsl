/* hello_dialog.c −− your typical Hello World program using
* an InformationDialog.
*/
#include <Xm/RowColumn.h>
#include <Xm/MessageB.h>
#include <Xm/PushB.h>

#include <stdio.h>
#include <stdlib.h>

static void popup_cb(Widget button, XtPointer client_data, XtPointer call_data);
static void activate_cb(Widget dialog, XtPointer client_data, XtPointer call_data);
static void exit_cb(Widget dialog, XtPointer client_data, XtPointer call_data);

int main(int argc, char **argv)
{
    XtAppContext app;
    Widget toplevel, rc, pb;

    XtSetLanguageProc (NULL, NULL, NULL);

    toplevel = XtVaAppInitialize (&app, "Demos", NULL, 0, &argc, argv, NULL, NULL);

    rc = XtVaCreateWidget ("rowcol", xmRowColumnWidgetClass, toplevel, NULL);
 
    pb = XtVaCreateManagedWidget ("Click to display dialog", xmPushButtonWidgetClass, rc, NULL);
    XtAddCallback (pb, XmNactivateCallback, popup_cb, "Hello World");
 
    pb = XtVaCreateManagedWidget ("Exit", xmPushButtonWidgetClass, rc, NULL);
    XtAddCallback (pb, XmNactivateCallback, exit_cb, NULL);

    XtManageChild (rc);
    XtRealizeWidget (toplevel);
    XtAppMainLoop (app);
}

/* callback for the PushButtons. Popup an InformationDialog displaying
* the text passed as the client data parameter.
*/
static void popup_cb(Widget button, XtPointer client_data, XtPointer call_data)
{
    Widget dialog;
    XmString xm_string;
    Arg args[5];
    int n = 0;
    char *text = (char *) client_data;

    /* set the label for the dialog */
    xm_string = XmStringCreateLocalized (text);
    XtSetArg (args[n], XmNmessageString, xm_string); n++;

    /* Create the InformationDialog as child of button */
    dialog = XmCreateInformationDialog (button, "info", args, n);

    /* no longer need the compound string, free it */
    XmStringFree (xm_string);

    /* add the callback routine */
    XtAddCallback (dialog, XmNokCallback, activate_cb, NULL);

    /* manage the dialog */
    XtManageChild (dialog);
}

/* callback routine for when the user presses the OK button.
* Yes, despite the fact that the OK button was pressed, the
* widget passed to this callback routine is the dialog!
*/
static void activate_cb(Widget dialog, XtPointer client_data, XtPointer call_data)
{
    printf("OK was pressed\n");
}

static void exit_cb(Widget dialog, XtPointer client_data, XtPointer call_data)
{
    exit(0);
}