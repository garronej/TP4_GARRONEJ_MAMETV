#! /bin/sh


gnuplot <<EOF
set term png
set output "out.png"
plot [1.8:7.2][2.8:6.2] "$1" w l
EOF
gnome-open out.png

