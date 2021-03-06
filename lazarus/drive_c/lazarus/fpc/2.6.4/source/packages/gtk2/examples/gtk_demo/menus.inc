(* Menus
 *
 * There are several widgets involved in displaying menus. The
 * GtkMenuBar widget is a horizontal menu bar, which normally appears
 * at the top of an application. The GtkMenu widget is the actual menu
 * that pops up. Both GtkMenuBar and GtkMenu are subclasses of
 * GtkMenuShell; a GtkMenuShell contains menu items
 * (GtkMenuItem). Each menu item contains text and/or images and can
 * be selected by the user.
 *
 * There are several kinds of menu item, including plain GtkMenuItem,
 * GtkCheckMenuItem which can be checked/unchecked, GtkRadioMenuItem
 * which is a check menu item that's in a mutually exclusive group,
 * GtkSeparatorMenuItem which is a separator bar, GtkTearoffMenuItem
 * which allows a GtkMenu to be torn off, and GtkImageMenuItem which
 * can place a GtkImage or other widget next to the menu text.
 *
 * A GtkMenuItem can have a submenu, which is simply a GtkMenu to pop
 * up when the menu item is selected. Typically, all menu items in a menu bar
 * have submenus.
 *
 * The GtkOptionMenu widget is a button that pops up a GtkMenu when clicked.
 * It's used inside dialogs and such.
 *
 * GtkItemFactory provides a higher-level interface for creating menu bars
 * and menus; while you can construct menus manually, most people don't
 * do that. There's a separate demo for GtkItemFactory.
 *
 *)


var
  menu_window : PGtkWidget;

function create_menu (depth   : gint;
                      tearoff : gboolean): PGtkWidget;
var
  menu,
  menuitem : PGtkWidget;

  group    : PGSList;
  buf      : pgchar;
  i, j     : gint;

begin

  if depth < 1 then
    exit (NULL);

  menu  := gtk_menu_new ();
  group := NULL;

  if tearoff then
  begin
    menuitem := gtk_tearoff_menu_item_new ();
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);
  end;

  j:=1;
  for i:=0 to 4 do
  begin
    buf := g_strdup_printf ('item %2d - %d', [depth, j]);
    menuitem := gtk_radio_menu_item_new_with_label (group, buf);
    group := gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menuitem));

    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);

    if i = 3 then
      gtk_widget_set_sensitive (menuitem, FALSE);

    gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), create_menu (depth - 1, TRUE));

    g_free (buf);
    inc (j);
  end;

  create_menu := menu;
end;

function do_menus          : PGtkWidget;
var
  box1,
  box2,
  button,
  optionmenu,
  separator,
  menubar,
  menu,
  menuitem     : PGtkWidget;

  accel_group  : PGtkAccelGroup;

begin
  if menu_window = NULL then
  begin
    menu_window := gtk_window_new (GTK_WINDOW_TOPLEVEL);

    g_signal_connect (menu_window, 'destroy',
                        G_CALLBACK(@gtk_widget_destroyed), @menu_window);
    g_signal_connect (menu_window, 'delete-event',
                        G_CALLBACK (@gtk_true), NULL);

    accel_group := gtk_accel_group_new ();
    gtk_window_add_accel_group (GTK_WINDOW (menu_window), accel_group);

    gtk_window_set_title (GTK_WINDOW (menu_window), 'Menus');
    gtk_container_set_border_width (GTK_CONTAINER (menu_window), 0);


    box1 := gtk_vbox_new (FALSE, 0);
    gtk_container_add (GTK_CONTAINER (menu_window), box1);
    gtk_widget_show (box1);

    menubar := gtk_menu_bar_new ();
    gtk_box_pack_start (GTK_BOX (box1), menubar, FALSE, TRUE, 0);
    gtk_widget_show (menubar);

    menu := create_menu (2, TRUE);

    menuitem := gtk_menu_item_new_with_label ('test'#13#10'line2');
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), menu);
    gtk_menu_shell_append (GTK_MENU_SHELL (menubar), menuitem);
    gtk_widget_show (menuitem);

    menuitem := gtk_menu_item_new_with_label ('foo');
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), create_menu (3, TRUE));
    gtk_menu_shell_append (GTK_MENU_SHELL (menubar), menuitem);
    gtk_widget_show (menuitem);

    menuitem := gtk_menu_item_new_with_label ('bar');
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem), create_menu (4, TRUE));
    gtk_menu_item_set_right_justified (GTK_MENU_ITEM (menuitem), TRUE);
    gtk_menu_shell_append (GTK_MENU_SHELL (menubar), menuitem);
    gtk_widget_show (menuitem);

    box2 := gtk_vbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    gtk_box_pack_start (GTK_BOX (box1), box2, TRUE, TRUE, 0);
    gtk_widget_show (box2);

    menu := create_menu (1, FALSE);
    gtk_menu_set_accel_group (GTK_MENU (menu), accel_group);

    menuitem := gtk_separator_menu_item_new ();
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);

    menuitem := gtk_check_menu_item_new_with_label ('Accelerate Me');
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);
    gtk_widget_add_accelerator (menuitem,
                 'activate',
                  accel_group,
                  GDK_KEY_F1,
                  0,
                  GTK_ACCEL_VISIBLE);

    menuitem := gtk_check_menu_item_new_with_label ('Accelerator Locked');
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);
    gtk_widget_add_accelerator (menuitem,
                 'activate',
                  accel_group,
                  GDK_KEY_F2,
                  0,
                  GTK_ACCEL_VISIBLE or GTK_ACCEL_LOCKED);

    menuitem := gtk_check_menu_item_new_with_label ('Accelerators Frozen');
    gtk_menu_shell_append (GTK_MENU_SHELL (menu), menuitem);
    gtk_widget_show (menuitem);
    gtk_widget_add_accelerator (menuitem,
                 'activate',
                  accel_group,
                  GDK_KEY_F2,
                  0,
                  GTK_ACCEL_VISIBLE);

    gtk_widget_add_accelerator (menuitem,
                 'activate',
                  accel_group,
                  GDK_KEY_F3,
                  0,
                  GTK_ACCEL_VISIBLE);

    optionmenu := gtk_option_menu_new ();
    gtk_option_menu_set_menu (GTK_OPTION_MENU (optionmenu), menu);
    gtk_option_menu_set_history (GTK_OPTION_MENU (optionmenu), 3);
    gtk_box_pack_start (GTK_BOX (box2), optionmenu, TRUE, TRUE, 0);
    gtk_widget_show (optionmenu);

    separator := gtk_hseparator_new ();
    gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 0);
    gtk_widget_show (separator);

    box2 := gtk_vbox_new (FALSE, 10);
    gtk_container_set_border_width (GTK_CONTAINER (box2), 10);
    gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, TRUE, 0);
    gtk_widget_show (box2);

    button := gtk_button_new_with_label ('close');
    g_signal_connect_swapped (button, 'clicked',
                                G_CALLBACK(@gtk_widget_destroy), menu_window);

    gtk_box_pack_start (GTK_BOX (box2), button, TRUE, TRUE, 0);
    GTK_WIDGET_SET_FLAGS (button, GTK_CAN_DEFAULT);
    gtk_widget_grab_default (button);
    gtk_widget_show (button);
  end;

  if not GTK_WIDGET_VISIBLE (menu_window) then
    gtk_widget_show (menu_window)
  else begin
    gtk_widget_destroy (menu_window);
    menu_window := NULL;
  end;

  do_menus := menu_window;
end;
