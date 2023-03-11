#include <bits/stdc++.h>
#include <chrono>
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
#define FORi(i,a,b)      	for(int32_t i=a;i<=b;i++)
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
#define fi					first
#define se					second 
#define str					string
#define int					long long 
#define endline				"\n"
#define spaceuk				" "
#define driver				int32_t
#define vi					vector<int32_t>
#define qi					queue<int32_t>
#define reset(a,b)			memset(a,b,sizeof(a))
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
/************************* Matrix **************************/
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
//predefined functions:
int32_t getbit(int32_t i, int32_t x){return ((x >> i) & 1);}
#define MID (ll + (rr - ll) / 2)
#define LEFT id,ll,MID;
#define RIGHT id,MID+1,rr
struct st{
    struct T_{
        int32_t val = 0;
    };
    int32_t n;
    vector<T_> tree;
    st(int32_t n_) : n(n_), tree(4 * n) {}
    void update(int32_t pos, int32_t value, int32_t id, int32_t ll, int32_t rr)
    {
        if (ll == rr) 
            tree[id].val = value;
        else 
        {
            int32_t m = MID;
            if (m >= pos) update(pos, value, 2 * id + 1, ll, m);
            else update(pos, value, 2 * id + 2, m + 1, rr);
            tree[id].val = tree[2 * id + 1].val + tree[2 * id + 2].val;
        }
    }
    void update(int32_t pos, int32_t value)
    {
        update(pos, value, 0, 0, n - 1);
    }
    int32_t query(int32_t k, int32_t id, int32_t ll, int32_t rr)
    {
        if (ll == rr) return ll;
        int32_t m = MID;
        if (k < tree[2 * id + 1].val) return query(k, 2 * id + 1, ll, m);
        return query(k - tree[2 * id + 1].val, 2 * id + 2, m + 1, rr);
    }
    int32_t query(int32_t k)
    {
        if (k >= tree[0].val)
            return n;
        return query(k, 0, 0, n - 1);
    }
};
/***********************************************************/
//variables below this line:
/***********************************************************/
//functions declarations:

/***********************************************************/
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
    //code below this line:
    int32_t n; cin >> n;
    vector<int32_t> colour(n);
    forv(v, colour) {cin >> v; v --;}
    st seggs(n);        //pun intended dont tryna be sexual 
    vector<int32_t> undo(n);
    vector<int32_t> next_colour(n, n);
    for(int32_t i = n - 1; i >= 0; i --)
    {
        int32_t next = next_colour[colour[i]];
        undo[i] = next;
        if (next != n)
            seggs.update(next, 0);
        seggs.update(i, 1);
        next_colour[colour[i]] = i;
    }
    vector<vector<int32_t>> queries(n);
    fr1(i, n) queries[0].pb(i);
    vector<int32_t> ans(n, 0);
    fr(i, n)
    {
        forv(v, queries[i])
        {
            int32_t v_th = seggs.query(v);
            if (v_th != n)
                queries[v_th].pb(v);
            ans[v - 1] ++;
        }
        if (undo[i] != n)
            seggs.update(undo[i], 1);
        seggs.update(i, 0);
    }
    forv(v, ans) cout << v << spaceuk;
    cout << endline;
    finish();
    return 0;
}
//functions content: