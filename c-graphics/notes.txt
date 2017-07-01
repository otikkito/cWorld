gtk
http://recolog.blogspot.com/2011/08/gui-programming-with-c-language-on.html
yum install gtk+.x86_64 gtk3-devel.x86_64
yum install glade   --> https://glade.gnome.org/
glade tutorial ---> http://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/
yum install gtk-doc.noarch
/usr/share/doc/gtk-doc-1.19/
yum install gtk3-devel.x86_64 gtk3-devel-docs.x86_64 glib-devel
Official reference: https://developer.gnome.org/gtk3/stable/gtk-getting-started.html

Compile notes:
gcc -g -Wall -pedantic -I /usr/include/gtk-3.0/  -I /usr/include/glib-1.2 gtk-hello-world.c 
