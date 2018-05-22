#include "handlingFunction.h"
#include "xulyfile.h"
void inital(int argc, char **argv)
{

    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *layoutbox;

    GtkWidget *searchButton;

    GtkWidget *titleButton;
    GtkWidget *comboBox;
    GtkWidget *newButton;
    GtkWidget *editButton;
    GtkWidget *deleteButton;
    GtkWidget *notebook;

    GtkWidget *titleBox;
    GtkWidget *newBox;
    GtkWidget *editBox;
    GtkWidget *deleteBox;
    char a[25][100]={"welcome","to","my","dictionary","by","Dragon's","group !"};

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Tu dien ANH - VIET by DragonGroup!");
    gtk_container_set_resize_mode (GTK_CONTAINER (window),FALSE);
    gtk_window_set_default_size (GTK_WINDOW (window), 1200,800);
    g_signal_connect (window, "delete_event", gtk_main_quit, NULL); /* dirty */

    layout=gtk_layout_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(window), layout);
    layoutbox = xpm_label_box2 ("image/nen1.jpg");
    gtk_container_add (GTK_CONTAINER (layout), layoutbox);
    gtk_widget_show(layout);
    gtk_widget_show (layoutbox);


    view = create_view_and_model (a,23);
   	gtk_container_set_border_width (GTK_CONTAINER (view), 10);

    gtk_layout_put (GTK_LAYOUT(layout),view,20,120);
    gtk_widget_set_size_request(view,215,550);


    GtkWidget *layout1;
    GtkWidget *label2;
    GtkWidget *label3;

    int i;
    char bufferf[32];
    char bufferf2[32];
    char bufferf3[32];
    char bufferl[32];

    notebook = gtk_notebook_new ();
    gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_TOP);
    gtk_widget_show (notebook);

	for (i = 0; i < 4; i++) {
            layout1=gtk_layout_new(NULL,NULL);
            gtk_widget_show(layout1);
            gtk_widget_set_size_request (layout1, 100, 75);
        if(i==0)
        {

            sprintf (bufferl, "Nghĩa");
                meaningTextView=gtk_text_view_new();
                buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(meaningTextView));
                gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
                const gchar *entry_text="xin chao";
                //gtk_text_buffer_set_text (buffer,chaoMung,-1);

        gtk_layout_put (GTK_LAYOUT(layout1),meaningTextView,0,0);
        }
        if(i==1) //add
        {

            sprintf (bufferf2, "từ");
            sprintf (bufferf3, "nghĩa");
            sprintf (bufferl, "Mới");

             addWordEntry=gtk_entry_new ();
        gtk_layout_put (GTK_LAYOUT(layout1),addWordEntry,100,50);

        addMeaningEntry=gtk_entry_new ();
        gtk_layout_put (GTK_LAYOUT(layout1),addMeaningEntry,100,90);
        addUpdateButton=gtk_button_new_with_label ("Thêm");
        g_signal_connect (addUpdateButton, "clicked",G_CALLBACK (addUpdate),notebook);
        gtk_layout_put (GTK_LAYOUT(layout1),addUpdateButton,300,90);


        label2 = gtk_label_new (bufferf2);
        gtk_layout_put (GTK_LAYOUT(layout1),label2,40,50);
        gtk_widget_show (label2);

        label3 = gtk_label_new (bufferf3);
        gtk_layout_put (GTK_LAYOUT(layout1),label3,40,90);
        gtk_widget_show (label3);
        }
        if(i==2) //edit
        {
            sprintf (bufferf, "Tìm từ");
            sprintf (bufferf2, " ");
            sprintf (bufferf3, "nghĩa");
            sprintf (bufferl, "Sửa");


            editSearchEntry=gtk_entry_new ();
            gtk_layout_put (GTK_LAYOUT(layout1),editSearchEntry,100,10);

            editSearchButton=gtk_button_new_with_label ("Tìm");
                g_signal_connect (editSearchButton, "clicked",G_CALLBACK (editSearchFunction),notebook);

            gtk_layout_put (GTK_LAYOUT(layout1),editSearchButton,300,10);
            editMeaningEntry=gtk_entry_new ();
            gtk_layout_put (GTK_LAYOUT(layout1),editMeaningEntry,100,90);

            editUpdateButton=gtk_button_new_with_label ("Sửa");
            g_signal_connect (editUpdateButton, "clicked",G_CALLBACK (editUpdateFunction),notebook);
           gtk_layout_put (GTK_LAYOUT(layout1),editUpdateButton,300,90);

            label2 = gtk_label_new (bufferf2);
        gtk_layout_put (GTK_LAYOUT(layout1),label2,40,50);
        gtk_widget_show (label2);

        label3 = gtk_label_new (bufferf3);
        gtk_layout_put (GTK_LAYOUT(layout1),label3,40,90);
        gtk_widget_show (label3);
        }
        if(i==3)
        {
            sprintf (bufferf, "Tìm từ");
            sprintf (bufferf2, " ");
            sprintf (bufferf3, "kết quả");
            sprintf (bufferl, "Xóa");

            deleteSearchEntry=gtk_entry_new ();
            gtk_layout_put (GTK_LAYOUT(layout1),deleteSearchEntry,100,10);

            deleteSearchButton=gtk_button_new_with_label ("Xóa");
            g_signal_connect (deleteSearchButton, "clicked",G_CALLBACK (deleteUpdateFunction),notebook);
            gtk_layout_put (GTK_LAYOUT(layout1),deleteSearchButton,300,10);
            deleteMeaningEntry=gtk_entry_new ();
            gtk_layout_put (GTK_LAYOUT(layout1),deleteMeaningEntry,100,90);
            label2 = gtk_label_new (bufferf2);
        gtk_layout_put (GTK_LAYOUT(layout1),label2,40,50);
        gtk_widget_show (label2);

        label3 = gtk_label_new (bufferf3);
        gtk_layout_put (GTK_LAYOUT(layout1),label3,40,90);
        gtk_widget_show (label3);

        }
        label = gtk_label_new (bufferl);
        gtk_notebook_append_page (GTK_NOTEBOOK (notebook), layout1, label);
    }
    gtk_notebook_set_current_page (GTK_NOTEBOOK (notebook), 0);
    gtk_widget_set_size_request(notebook,400,550);

    gtk_layout_put (GTK_LAYOUT(layout),notebook,400,120);

    newButton = gtk_button_new ();
    g_signal_connect (newButton, "clicked",G_CALLBACK (addTab),notebook);
    newBox = xpm_label_box ("image/new.png", "Mới");
    gtk_widget_set_size_request(newButton,100,45);
    gtk_widget_show (newBox);
    gtk_container_add (GTK_CONTAINER (newButton), newBox);
    gtk_layout_put (GTK_LAYOUT(layout),newButton,400,60);

    editButton = gtk_button_new ();
    g_signal_connect (editButton, "clicked",G_CALLBACK (editTab),notebook);
    editBox = xpm_label_box ("image/edit.png", "Sửa");
    gtk_widget_set_size_request(editButton,100,45);
    gtk_widget_show (editBox);
    gtk_container_add (GTK_CONTAINER (editButton), editBox);
    gtk_layout_put (GTK_LAYOUT(layout),editButton,550,60);

    deleteButton = gtk_button_new ();
    g_signal_connect (deleteButton, "clicked",G_CALLBACK (deleteTab),notebook);
    deleteBox = xpm_label_box ("image/delete.png", "Xóa");
    gtk_widget_set_size_request(deleteButton,100,45);
    gtk_widget_show (deleteBox);
    gtk_container_add (GTK_CONTAINER (deleteButton), deleteBox);
    gtk_layout_put (GTK_LAYOUT(layout),deleteButton,700,60);

    searchButton=gtk_button_new_with_label ("Tìm");
    g_signal_connect (searchButton, "clicked",G_CALLBACK (searchMainFunction),notebook);
    gtk_layout_put (GTK_LAYOUT(layout),searchButton,200,60);

    searchEntry=gtk_search_entry_new ();
    g_signal_connect ((gpointer) searchEntry, "focus",G_CALLBACK (enter_callback2),NULL);
    gtk_layout_put (GTK_LAYOUT(layout),searchEntry,20,60);
    g_signal_connect (searchEntry, "search-changed",G_CALLBACK (suggestFunction),notebook);
    g_signal_connect (searchEntry, "activate",G_CALLBACK (searchMainFunction),notebook);



    gtk_widget_show_all (window);

    btinit();

    root=btopn("data",0,0);
    if(!root){
        printf("Creating data\n");
        creat(&root,"anhviet2.txt");
    }
    soundexTree=btopn("soundexTree",0,0);
    if(!soundexTree){
        printf("creating soundextree\n");
        creatSoundexTree(root,&soundexTree);
    }
    gtk_main ();
}
