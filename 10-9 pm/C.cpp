#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define sexually_transferred_diseases std				//Why not
using namespace sexually_transferred_diseases;			//UwU
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⣒⠯⣙⡟⠶⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⣥⠳⣘⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⢤⢶⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡚⣤⢓⡹⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠴⡺⢍⡲⣉⢾⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣧⢋⡵⢢⢤⡀⠀⠀⠀⠀⠀⠀⠀⠘⢷⣦⣯⣔⣳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⡞⢭⣊⠵⢣⡽⢚⡿⢌⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢱⠢⢷⣩⢒⣍⠲⣩⠛⣶⣤⡀⠀⠀⠀⠀⠀⠙⢿⣻⣟⡿⣷⣤⣀⡤⢤⠤⡴⣒⢖⡲⣒⠶⠤⣤⣠⣴⣿⢿⣧⡙⡲⣬⣾⡏⠀⣼⠲⣩⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠈⢣⠀⠈⠙⠮⢧⡥⢛⢼⣟⡿⣷⣤⡀⠀⣀⡤⠤⢴⡛⢭⢣⢍⠳⡌⣇⢣⡓⣜⢢⡕⢮⣾⣿⢿⣟⣯⡿⣯⣿⣮⢿⡝⡾⠀⠸⣥⣳⢡⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠘⡆⠀⢰⡦⣄⣹⠿⣿⣯⢿⣯⡿⢫⠝⣢⡵⣋⢦⡙⢦⢋⡬⢓⡱⣊⠵⣘⠦⣃⠞⣔⠪⡝⠿⢾⣻⣽⣷⢿⡹⣎⢷⡃⠀⠀⠀⠈⢉⣻⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣷⠀⢸⡥⢛⡛⢶⡛⡟⢾⠛⡷⣚⠶⣋⢧⡹⣌⠳⣌⠞⣡⠞⡥⢛⡔⢫⡔⢫⠴⡙⣆⠳⡔⡪⢭⡙⢏⡞⣧⡻⣬⡇⠀⠀⠠⢴⣚⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣿⡄⠀⢯⢣⡙⢦⡱⢎⢣⢫⢔⣣⡾⠳⣍⠳⣌⠳⣌⠞⣡⠞⣡⠏⡜⡥⡚⢥⢫⠜⡆⢏⡶⡙⢦⡙⢎⡴⡡⠿⣧⡇⠀⠀⠀⠀⠙⠾⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⡧⢷⠀⠘⣧⣙⠦⡱⢎⣣⢣⡾⡳⠚⡗⣌⠳⣌⠳⡌⢞⡡⢞⡡⢞⣱⡸⢥⢋⢦⠛⣌⠧⡗⡭⠎⣊⠇⠶⣙⢬⣹⣷⣄⠀⠀⠀⢀⣴⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⡠⠤⠛⠉⠀⠀⠈⢻⣿⣟⣿⣿⣿⠣⣕⠪⣍⣧⣿⡌⢧⣹⣎⡜⢦⠹⣌⢦⡑⢎⡚⡴⢋⢦⣿⢗⡡⢏⢦⡙⣎⡱⠲⣼⣟⣿⣦⣀⣶⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠙⠒⠤⢤⣀⠀⠀⠀⣸⡝⣿⣿⣳⡏⣵⣮⢿⣟⣯⣟⣯⠆⣿⣯⡜⡬⢓⡜⣢⠝⣌⠳⢬⣹⣾⣿⣷⣍⢎⡲⢱⡸⣔⣿⣽⣻⣾⣻⣿⣿⡷⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣿⢿⠀⢰⣏⣾⣿⢯⡿⣟⣷⢿⣯⡿⣽⣾⣻⣿⡿⣽⣿⣴⣋⡴⢃⣞⣬⣷⡿⣿⠋⢳⣯⡿⣟⣿⣟⣿⣻⣽⡾⣯⣷⢿⡾⣽⡿⣿⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⣿⣿⢀⣷⣿⢿⡽⣟⣿⣻⣽⢿⣞⣿⢯⣷⣿⡿⣽⣟⣾⣽⢿⣻⣿⣻⣟⣾⠟⠁⢠⠄⢻⣿⣻⢷⣻⣽⣯⣷⣿⣻⢾⣟⣿⣽⣻⣽⣿⠿⠖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢹⣿⣺⣿⢯⣿⣻⢿⣽⣻⣾⡿⠿⠚⠉⣴⣿⣟⣿⠞⣹⣿⣻⢯⣷⢿⡽⠋⢀⠌⠁⠈⠄⢿⣿⣻⣯⣷⣿⢏⣹⣿⡿⣿⣟⡿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢛⣿⣯⣿⣷⠿⠿⠿⣿⢷⠚⠛⣿⣿⣿⣿⣾⣷⡄⣾⣿⣽⣿⣿⠿⢶⣿⣷⣶⣶⣶⣴⣬⣿⣷⣟⣾⢏⢦⣹⣷⡟⣛⢻⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⡿⠊⣹⠴⡩⣍⡓⢾⢹⣷⣶⣿⣿⣿⣿⣿⣿⢣⣿⣯⣿⠟⢸⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⡟⡬⠲⣼⡷⡘⢦⢓⡚⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠋⣠⢚⣼⣷⡱⢆⡹⢺⠈⢿⣿⣿⣿⣿⣿⣿⠏⣸⣿⠟⠁⠀⠈⢿⣿⣿⣿⣿⣿⣿⣿⡿⣻⣿⡟⡜⢲⡙⣼⢲⡙⢆⡫⢜⠲⣌⣫⠟⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⢴⡛⢬⠲⡌⢿⣿⣮⣕⣫⡆⠈⠛⠻⠿⠛⠛⠁⠀⠛⠁⠀⠀⠀⠀⠈⠛⠿⣿⣿⡿⢿⢫⡗⡥⡿⠜⣜⢣⣱⡟⢦⡙⣬⣱⣮⠗⠋⠄⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠛⠲⠛⠦⠯⣼⣉⢿⣟⣿⣻⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢧⢱⠩⢞⣰⣷⡟⡱⡗⠛⠋⠁⠀⠀⠀⠀⠘⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠰⠠⢀⠀⢢⡇⡎⣽⣿⡽⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⠀⠀⠀⠀⠀⢀⠈⠠⣿⣷⡿⣿⢿⣿⢏⠼⣡⢻⡀⠀⢄⠀⠀⠀⠀⡁⢣⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⠈⠐⠈⣷⣱⣏⠿⣷⣿⡆⠀⠀⠀⠀⠀⠀⠂⠐⠀⠒⠈⠀⠀⠀⠀⠀⠠⠊⢀⢰⣿⣯⡷⣟⣾⠋⠺⣴⣩⢚⡇⠂⢈⠀⠀⠀⠀⢡⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⠀⠀⠀⠘⣄⠀⠀⠈⢱⣎⢳⡹⢿⣿⡷⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠐⣀⣿⣿⣳⡿⠫⢎⡀⠀⠀⠙⠮⡟⠀⢈⠀⠠⢀⠂⠄⣸⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀
⠀⢸⠁⢄⠀⠀⠘⢆⠀⠂⠈⣎⢧⡙⢾⡛⠛⠉⢀⢩⠒⠦⠤⣤⣀⣀⣀⣀⣀⣮⢤⣾⠖⡛⢩⣿⠗⡋⠤⠂⠂⣈⠽⠀⠀⠀⠀⢀⠀⣀⡴⣇⠰⣆⠇⠀⠀⢀⠎⢸⠀⠀⠀⠀⠀
⠀⠈⡆⡀⠑⠠⡀⠈⠳⣄⠀⠘⡶⣙⢦⡛⢶⢄⡀⠀⠀⡩⠁⠸⣷⣤⣄⣀⣤⣶⠾⡉⢠⠤⠟⠁⠀⣠⠴⣮⡁⠀⠀⠀⠀⠐⢈⣠⠼⣱⠳⣜⢫⠎⠀⢀⠔⠁⠀⠘⡀⠀⠀⠀⠀
⠀⠀⢡⠀⠀⠀⠈⡑⠤⢀⣉⡒⠽⠼⣦⠝⣑⡐⡟⠀⢈⡉⠀⢇⢼⣿⣿⣿⣿⡿⠀⠐⠆⠀⡀⠀⠈⡆⡄⢀⠛⢓⣤⡦⢵⠺⣍⢎⡳⢥⡛⣬⠋⡠⠖⠑⠀⠀⠀⢠⠁⠀⠀⠀⠀
⠀⠀⠀⢇⠂⠀⠀⠐⠀⠀⠀⢀⡴⢋⡠⡑⠄⢊⢗⠊⣥⣧⣴⠶⣾⣟⣿⣻⢿⣧⡒⡄⡜⢥⡉⣗⠲⣼⠜⠁⢀⠎⠸⣝⡻⣵⡎⢮⣱⡧⣛⠕⠈⠀⠀⠘⠀⠀⡠⢺⠀⠀⠀⠀⠀
⠀⠀⠀⠈⢦⡙⡖⣦⢤⣤⠞⣉⠔⣢⠱⣉⢎⢂⠁⣷⡘⡗⢩⢉⢸⣿⣾⣯⣿⣿⠘⡊⠍⠦⢱⣸⣗⢀⢰⠐⡡⢊⡀⠈⡑⢧⣛⢯⣐⠈⠀⠀⠀⠠⠐⠈⣨⠞⡧⡚⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠉⠚⣶⡋⢄⠲⣡⠚⡤⢓⡌⣎⣞⣳⡼⣩⡗⠢⠌⣻⣿⣳⢿⣽⣻⠀⠁⢀⠂⠄⣗⢮⡟⡥⡘⣌⢣⡙⢆⠠⢀⠙⢮⡝⣳⢦⣄⠀⢀⣤⠻⣥⠻⡱⠁⠀⠀⠀⠀⠀
⢰⠄⡀⠀⠀⠀⡊⠁⠙⢮⡓⢤⢋⡔⣣⢞⡵⣮⢟⣲⡵⣁⣉⢉⣿⣿⣻⣿⣻⣿⡁⠔⠁⡈⢰⣏⢾⡯⣝⣧⡘⢆⡱⢊⡍⢦⡐⢀⠘⢣⡏⣾⢳⣻⣬⠳⠊⠔⠀⠀⢀⠀⠤⠐⠰
⠈⡆⠀⠁⠂⢸⠙⣤⠁⠠⠙⢮⣲⣜⢷⣫⢾⡙⣮⠏⣔⣶⣾⣴⣿⣿⣿⡾⣿⣿⡈⠉⠉⠉⢉⣉⣉⡷⣩⢏⣷⡊⡔⢣⠜⣢⢑⠣⢆⣠⠞⢫⡳⣜⣺⠒⠄⠀⠀⠉⠀⠀⠀⢀⠆
⠀⢡⠀⡀⠀⠀⠣⣈⠲⣁⠰⣜⡳⣯⡾⢣⢇⣿⢏⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣴⣭⣵⣭⣹⣏⡞⣧⣓⢎⡖⣻⣌⢣⠚⡤⢋⡼⠚⠁⡀⠂⢙⡼⠁⢀⠀⢀⠃⠀⠀⠀⠀⡌⠀
⠀⠀⢃⠀⣄⠀⠀⠠⠑⠚⠛⣶⡹⢯⡱⣋⢾⣿⣞⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡹⣝⣷⠮⣜⡱⢻⣆⡹⣰⠏⡰⢶⠁⢠⡵⠫⠁⢀⠌⡠⠁⠀⠀⠀⠀⡜⠀⠀
⠀⠀⠈⠣⣀⠊⢄⣀⡬⣟⡹⢆⣛⢦⣳⣿⣿⣷⣯⣭⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢻⡜⡾⣿⡰⣍⠳⣎⠿⣅⡸⠟⢀⡴⠯⠴⠤⠔⠁⠀⠀⠁⡘⠀⢐⠜⠀⠀⠀
⠀⠀⠀⠀⠈⠑⠪⠌⣒⠣⢝⣾⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠀⠹⣿⣿⣿⣿⢿⠿⣏⣷⣹⣳⠽⡗⣎⢳⢬⠳⣭⡝⠛⠋⠀⠀⠀⠀⠀⠀⠠⣐⢤⠔⡤⠊⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠋⣤⣾⣿⣿⣿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀⠀⠀⢿⣿⣿⣿⣾⣶⣿⠿⡻⣿⣶⣣⡝⢮⡜⢦⣍⢳⡒⠶⡒⠖⣀⣀⡤⢖⣲⠫⢊⠔⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣝⣿⣟⣿⣿⣧⣙⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⡟⣡⣷⣿⠿⣷⣿⣿⣦⡝⡲⢬⢣⡝⣣⢝⡹⢆⡳⡼⢓⡨⠒⠁⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢹⣾⡏⢭⡙⢿⣿⣿⣮⢟⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣏⣼⣿⣿⣧⣇⣿⣿⣿⣹⣿⣟⠺⠥⣎⣑⣈⣣⠭⠔⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⣢⣞⢯⣿⣿⣟⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣳⡟⢦⡹⢯⡘⢼⣫⡝⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠟⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣇⠣⡜⢢⢷⡹⣎⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⡒⡍⢆⣯⢳⣭⣿⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣿⣷⣮⣾⠿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
//array <class T, size_t N> arr;
//vector <class T, class Alloc = allocator<T>> vector;
//deque <class T, class Alloc = allocator<T> > deque;
//priority_queue <class T, class Container = vector<T>,class Compare = less<typename Container::value_type>> priority_queue;
//queue <class T, class Container = deque<T>> queue;
//map <class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>> map;
#define FOR(i,a,b)      	for(int64_t i=a;i<=b;i++)
#define fr(i,n)         	for(int64_t i=0;i<n;i++)
#define fr1(i,n)        	for(int64_t i=1;i<=n;i++)
#define FORI(i,a,b)      	for(int32_t i=a;i<=b;i++)
#define fri(i,n)         	for(int32_t i=0;i<n;i++)
#define fr1i(i,n)        	for(int32_t i=1;i<=n;i++)
#define FORD(i, a, b)  		for(int64_t i=a;i>=b;i--)
#define FORDI(i, a, b)		for(int32_t i=a;i>=b;i--)
#define forv(a, b)			for(auto &a : b)
#define sortall(arr)   	 	sort(arr.begin(), arr.end())
#define sortallmax(arr)	 	sort(arr.begin(), arr.end(), greater<int64_t>())
#define elif				else if
#define pb					push_back
#define pf					push_front
#define mp					make_pair
#define str					string
#define int					long long 
#define endline				"\n"
#define spaceuk				" "
#define driver				int32_t
#define vi					vector<int32_t>
#define qi					queue<int32_t>
#define reset(a,b)			memset(a,b,sizeof(a))
#define uid(a, b)			uniform_int_distribution<int>(a, b)(rng)
#define TOINFINITYANDBEYOND	0x3f3f3f3f
#define PI					3.1415926535897932384626433832795
const long long MODULO =	1e9+7;
const double pi =			acos(-1.0);
auto start =				chrono::steady_clock::now();
void finish(){
	auto end = chrono::steady_clock::now();
	//cout << "Code run time: ";
	cout << chrono::duration<double, std::milli>(end - start).count() << "ms" << endl;
	fclose(stdin);
	fclose(stdout);
	return;
}
#define ultimate_matrix
/************************* Matrix **************************/
// FOR NORMAL PEOPLE:
#ifndef ultimate_matrix
const int64_t length = 2;
struct matrix{
	int64_t m[length][length];
};
matrix operator *(matrix a, matrix b)
{
	matrix c;
	fr(i,length) fr(j,length){
		c.m[i][j] = 0;
		fr(t,length) c.m[i][j] = (c.m[i][j] + (a.m[i][t] * b.m[t][j]) % MODULO) % MODULO;
	}
	return c;
}
matrix operator ^(matrix a, int64_t n)
{
	if (n == 1) return a;
	matrix temp = a ^ (n / 2);
	temp = temp * temp;
	if (n % 2 == 0) return temp;
	else return (temp * a);
}
/***********************************************************/
#else
/******************** ULTIMATE Matrix **********************/
template<int32_t _MODULO> struct Modular{
	int64_t v;
	explicit operator int32_t() const {return v;} //explicitly -> don't silently convert to int32_t
	Modular() {v = 0;}
	Modular(int64_t _v) 
	{
		v = int32_t((-_MODULO < _v && _v < _MODULO) ? _v : _v % _MODULO); 
		if (v < 0) v += _MODULO;
	}
	friend ostream& operator << (ostream& out, const Modular &n)
	{
		return out << int32_t(n);
	}
	friend istream& operator >> (istream& in, const Modular &n)
	{
		int64_t _v;
		in >> _v;
		n = Modular(_v);
		return in;
	}

	friend bool operator == (const Modular &a, const Modular &b) {return a.v == b.v;}
	friend bool operator != (const Modular &a, const Modular &b) {return a.v != b.v;}
	friend bool operator < (const Modular &a, const Modular &b) {return a.v < b.v;}
	friend bool operator > (const Modular &a, const Modular &b) {return a.v > b.v;}
	
	Modular& operator += (const Modular &m)
	{
		if ((v += m.v) > _MODULO)
			v -= _MODULO;
		return *this;
	}
	Modular& operator -= (const Modular &m)
	{
		if ((v -= m.v) < 0)
			v += _MODULO;
		return *this;
	}
	Modular& operator *= (const Modular &m)
	{
		v = int32_t((int64_t) v * m.v % _MODULO);
		return *this;
	}
	Modular& operator /= (const Modular &m)
	{
		return (*this) *= inv(m);
	}
	Modular operator - () const {return Modular(-v);}

	Modular &operator ++() {return *this += 1;}
	Modular &operator --() {return *this -= 1;}
	friend Modular pow(Modular a, int64_t p)
	{
		Modular ans = 1;
		assert(p >= 0);
		for(; p; p /= 2, a *= a)
			if (p & 1)
				ans *= a;
		return ans;
	}
	friend Modular inv(const Modular &a)
	{
		assert(a.v != 0);
		return pow(a, _MODULO - 2);
	}
	friend Modular operator + (Modular a, const Modular &b) {return a += b;}
	friend Modular operator - (Modular a, const Modular &b) {return a -= b;}
	friend Modular operator * (Modular a, const Modular &b) {return a *= b;}
	friend Modular operator / (Modular a, const Modular &b) {return a /= b;}
	friend Modular operator ++ (Modular &a, int32_t)
	{
		Modular r = a;
		++ a;
		return r;
	}
	friend Modular operator -- (Modular &a, int32_t)
	{
		Modular r = a;
		-- a;
		return r;
	}
};

template <class T> struct matrix{
	vector<vector<T>> m;
	int64_t r, c;
	matrix() : r(), c() {}
	matrix(int64_t r, int64_t c, T x) : r(r), c(c), m(r, vector<T> (c, x)) {}
	matrix(int64_t n) : matrix (n, n, 0) 	//identity matrix
	{
		for(int64_t i = 0; i < n; i ++)
			m[i][i] = 1;
	}
	matrix operator * (matrix<T> b)
	{
		matrix<T> a = *this;
		assert(a.c == b.r);
		matrix<T> c(a.r, b.c, 0);
		{
			for(int64_t i = 0; i < a.r; i ++)
				for(int64_t j = 0; j < b.c; j ++)
					for(int64_t k = 0; k < a.c; k ++)
						c.m[i][j] = c.m[i][j] + a.m[i][k] * b.m[k][j];
		}
		return c;
	}
	matrix operator ^ (int64_t b)
	{
		matrix<T> a = *this;
		assert(a.r == a.c);
		matrix<T> o(a.r);
		while(b)
		{
			if (b % 2)
				o = o * a;
			a = a * a;
			b /= 2;
		}
		return o;
	}
	void print()
	{
		for(int64_t i = 0; i < r; i ++)
		{
			for(int64_t j = 0; j < c; j ++)
				cout << m[i][j] << spaceuk;
			cout << endline;
		}

	}
};

using mint = Modular<MODULO>;
#endif
/***********************************************************/
#define BIGINT
/********************** THE BIG INT ************************/
#ifdef BIGINT
const int32_t base = 1000000000;
const int32_t base_digits = 9; 
struct int128_t {
	vector<int32_t> a;
	int32_t sign;

	int32_t size(){
		if(a.empty())return 0;
		int32_t ans=(a.size()-1)*base_digits;
		int32_t ca=a.back();
		while(ca)
			ans++,ca/=10;
		return ans;
	}
	int128_t operator ^(const int128_t &v){
		int128_t ans=1,a=*this,b=v;
		while(!b.isZero()){
			if(b%2)
				ans*=a;
			a*=a,b/=2;
		}
		return ans;
	}
	string to_string(){
		stringstream ss;
		ss << *this;
		string s;
		ss >> s;
		return s;
	}
	int32_t sumof(){
		string s = to_string();
		int32_t ans = 0;
		for(auto c : s)  ans += c - '0';
		return ans;
	}

	int128_t() :
		sign(1) {
	}
 
	int128_t(int64_t v) {
		*this = v;
	}
 
	int128_t(const string &s) {
		read(s);
	}
 
	void operator=(const int128_t &v) {
		sign = v.sign;
		a = v.a;
	}
 
	void operator=(int64_t v) {
		sign = 1;
		a.clear();
		if (v < 0)
			sign = -1, v = -v;
		for (; v > 0; v = v / base)
			a.push_back(v % base);
	}
 
	int128_t operator+(const int128_t &v) const {
		if (sign == v.sign) {
			int128_t res = v;
 
			for (int32_t i = 0, carry = 0; i < (int32_t) max(a.size(), v.a.size()) || carry; ++i) {
				if (i == (int32_t) res.a.size())
					res.a.push_back(0);
				res.a[i] += carry + (i < (int32_t) a.size() ? a[i] : 0);
				carry = res.a[i] >= base;
				if (carry)
					res.a[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}
 
	int128_t operator-(const int128_t &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				int128_t res = *this;
				for (int32_t i = 0, carry = 0; i < (int32_t) v.a.size() || carry; ++i) {
					res.a[i] -= carry + (i < (int32_t) v.a.size() ? v.a[i] : 0);
					carry = res.a[i] < 0;
					if (carry)
						res.a[i] += base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}
 
	void operator*=(int32_t v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int32_t i = 0, carry = 0; i < (int32_t) a.size() || carry; ++i) {
			if (i == (int32_t) a.size())
				a.push_back(0);
			int64_t cur = a[i] * (int64_t) v + carry;
			carry = (int32_t) (cur / base);
			a[i] = (int32_t) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}
 
	int128_t operator*(int32_t v) const {
		int128_t res = *this;
		res *= v;
		return res;
	}
 
	void operator*=(int64_t v) {
		if (v < 0)
			sign = -sign, v = -v;
		if(v > base){
			*this = *this * (v / base) * base + *this * (v % base);
			return ;
		}
		for (int32_t i = 0, carry = 0; i < (int32_t) a.size() || carry; ++i) {
			if (i == (int32_t) a.size())
				a.push_back(0);
			int64_t cur = a[i] * (int64_t) v + carry;
			carry = (int32_t) (cur / base);
			a[i] = (int32_t) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}
 
	int128_t operator*(int64_t v) const {
		int128_t res = *this;
		res *= v;
		return res;
	}
 
	friend pair<int128_t, int128_t> divmod(const int128_t &a1, const int128_t &b1) {
		int32_t norm = base / (b1.a.back() + 1);
		int128_t a = a1.abs() * norm;
		int128_t b = b1.abs() * norm;
		int128_t q, r;
		q.a.resize(a.a.size());
 
		for (int32_t i = a.a.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.a[i];
			int32_t s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
			int32_t s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
			int32_t d = ((int64_t) base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.a[i] = d;
		}
 
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return make_pair(q, r / norm);
	}
 
	int128_t operator/(const int128_t &v) const {
		return divmod(*this, v).first;
	}
 
	int128_t operator%(const int128_t &v) const {
		return divmod(*this, v).second;
	}
 
	void operator/=(int32_t v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int32_t i = (int32_t) a.size() - 1, rem = 0; i >= 0; --i) {
			int64_t cur = a[i] + rem * (int64_t) base;
			a[i] = (int32_t) (cur / v);
			rem = (int32_t) (cur % v);
		}
		trim();
	}
 
	int128_t operator/(int32_t v) const {
		int128_t res = *this;
		res /= v;
		return res;
	}
 
	int32_t operator%(int32_t v) const {
		if (v < 0)
			v = -v;
		int32_t m = 0;
		for (int32_t i = a.size() - 1; i >= 0; --i)
			m = (a[i] + m * (int64_t) base) % v;
		return m * sign;
	}
 
	void operator+=(const int128_t &v) {
		*this = *this + v;
	}
	void operator-=(const int128_t &v) {
		*this = *this - v;
	}
	void operator*=(const int128_t &v) {
		*this = *this * v;
	}
	void operator/=(const int128_t &v) {
		*this = *this / v;
	}
 
	bool operator<(const int128_t &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (a.size() != v.a.size())
			return a.size() * sign < v.a.size() * v.sign;
		for (int32_t i = a.size() - 1; i >= 0; i--)
			if (a[i] != v.a[i])
				return a[i] * sign < v.a[i] * sign;
		return false;
	}
 
	bool operator>(const int128_t &v) const {
		return v < *this;
	}
	bool operator<=(const int128_t &v) const {
		return !(v < *this);
	}
	bool operator>=(const int128_t &v) const {
		return !(*this < v);
	}
	bool operator==(const int128_t &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const int128_t &v) const {
		return *this < v || v < *this;
	}
 
	void trim() {
		while (!a.empty() && !a.back())
			a.pop_back();
		if (a.empty())
			sign = 1;
	}
 
	bool isZero() const {
		return a.empty() || (a.size() == 1 && !a[0]);
	}
 
	int128_t operator-() const {
		int128_t res = *this;
		res.sign = -sign;
		return res;
	}
 
	int128_t abs() const {
		int128_t res = *this;
		res.sign *= res.sign;
		return res;
	}
 
	int64_t longValue() const {
		int64_t res = 0;
		for (int32_t i = a.size() - 1; i >= 0; i--)
			res = res * base + a[i];
		return res * sign;
	}
 
	friend int128_t gcd(const int128_t &a, const int128_t &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend int128_t lcm(const int128_t &a, const int128_t &b) {
		return a / gcd(a, b) * b;
	}
 
	void read(const string &s) {
		sign = 1;
		a.clear();
		int32_t pos = 0;
		while (pos < (int32_t) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int32_t i = s.size() - 1; i >= pos; i -= base_digits) {
			int32_t x = 0;
			for (int32_t j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.push_back(x);
		}
		trim();
	}
 
	friend istream& operator>>(istream &stream, int128_t &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}
 
	friend ostream& operator<<(ostream &stream, const int128_t &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int32_t i = (int32_t) v.a.size() - 2; i >= 0; --i)
			stream << setw(base_digits) << setfill('0') << v.a[i];
		return stream;
	}
 
	static vector<int32_t> convert_base(const vector<int32_t> &a, int32_t old_digits, int32_t new_digits) {
		vector<int64_t> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int32_t i = 1; i < (int32_t) p.size(); i++)
			p[i] = p[i - 1] * 10;
		vector<int32_t> res;
		int64_t cur = 0;
		int32_t cur_digits = 0;
		for (int32_t i = 0; i < (int32_t) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int32_t(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int32_t) cur);
		while (!res.empty() && !res.back())
			res.pop_back();
		return res;
	}
 
	typedef vector<int64_t> vll;
 
	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int32_t n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int32_t i = 0; i < n; i++)
				for (int32_t j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
 
		int32_t k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());
 
		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);
 
		for (int32_t i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int32_t i = 0; i < k; i++)
			b2[i] += b1[i];
 
		vll r = karatsubaMultiply(a2, b2);
		for (int32_t i = 0; i < (int32_t) a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int32_t i = 0; i < (int32_t) a2b2.size(); i++)
			r[i] -= a2b2[i];
 
		for (int32_t i = 0; i < (int32_t) r.size(); i++)
			res[i + k] += r[i];
		for (int32_t i = 0; i < (int32_t) a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int32_t i = 0; i < (int32_t) a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}
 
	int128_t operator*(const int128_t &v) const {
		vector<int32_t> a6 = convert_base(this->a, base_digits, 6);
		vector<int32_t> b6 = convert_base(v.a, base_digits, 6);
		vll a(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(a, b);
		int128_t res;
		res.sign = sign * v.sign;
		for (int32_t i = 0, carry = 0; i < (int32_t) c.size(); i++) {
			int64_t cur = c[i] + carry;
			res.a.push_back((int32_t) (cur % 1000000));
			carry = (int32_t) (cur / 1000000);
		}
		res.a = convert_base(res.a, 6, base_digits);
		res.trim();
		return res;
	}
};
#endif
/***********************************************************/
//predefined functions:
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B, typename C>	struct threesome{
	A fi;
	B se;
	C th;
};
int64_t getbit(int32_t i, int64_t x){return ((x >> i) & 1);}
int64_t mul(int64_t a, int64_t b)
{
	int64_t res = 0;
	while (b > 0)
	{
		if (b % 2 == 1)
			res = (res + a);
		a = (a * 2);
		b /= 2;
	}
	return res;
}
int64_t power(int64_t a, int64_t b)
{
	int64_t res = 1;
	a %= b;
	if (a == 0) return 0;
	while(b > 0)
	{
		if (b & 1)
			res = mul(res, a);
		b /= 2;
		a = mul(a, a);
	}
	return res;
}
int64_t Modular_multiplication(int64_t a, int64_t b)
{
	int64_t res = 0;
	a %= MODULO;
	while (b > 0)
	{
		if (b % 2 == 1)
			res = (res + a) % MODULO;
		a = (a * 2) % MODULO;
		b /= 2;
	}
	return res % MODULO;
}
int64_t Modular_exponentiation(int64_t a, int64_t b)
{
	int64_t res = 1;
	a %= b;
	if (a == 0) return 0;
	while(b > 0)
	{
		if (b & 1)
			res = Modular_multiplication(res, a);
		b /= 2;
		a = Modular_multiplication(a, a);
	}
	return res;
}
int32_t T = 1;
/***********************************************************/
//Global variables below this line:

/***********************************************************/
//Functions declarations:

/***********************************************************/
void solve()
{
	//code below this line:
	
}
//Functions content:

// #define task "cells"
// #define standard_input 
#define input_extension ".inp"
#define output_extension ".out"
driver main(int32_t argc, char *argv[]){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.exceptions(cin.failbit);
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		#ifndef standard_input
			#ifdef task
				if (!fopen(task input_extension,"r"))
					return -1;
				(void)!freopen (task input_extension, "r", stdin);
				(void)!freopen (task output_extension, "w", stdout);
			#else
				if (!fopen("input.inp","r")) 
				{
					cerr << "U STUPID" << endline;
					return -1;
				}
				(void)!freopen ("input.inp","r",stdin);
				(void)!freopen ("output.out","w",stdout);
			#endif
		#endif
	}
	fr1(i, T)
		solve();
	if (argc == 1 || strcmp("stdinp", argv[1]) != 0)
	{
		#ifndef standard_input
			#ifndef task
				finish();
			#endif
		#endif
	}
	return 0;
}