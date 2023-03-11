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
int64_t power(int64_t a, int32_t b)
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
int64_t Modular_exponentiation(int64_t a, int32_t b)
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
/***********************************************************/
//variables below this line:
int32_t m, cc, k;

/***********************************************************/
//functions declarations:
#define MID  (ll + (rr - ll) / 2)
#define Lcon id * 2, ll, MID
#define Rcon id * 2 + 1, MID + 1, rr
struct largestIncreasingSubarray{
    int32_t st[4 * 100010], a[100010];
    pair<int32_t, int32_t> b[100010];
    void bruh(int32_t n)
    {
        fr1(i, n)
        {
            b[i].fi = a[i];
            b[i].se = i;
        }
        sort(b + 1, b + n + 1);
        int32_t val = INT_MIN, c = 0;
        fr1(i, n) 
        {
            if (b[i].fi != val)
            {
                val = b[i].fi;
                c ++;
            }
            a[b[i].se] = c;
        }
        fr1(i, n)   
        {
            int32_t k = 0;
            if (a[i] > 1) k = get(1, 1, n, 1, a[i] - 1);
            update(1, 1, n, a[i], k + 1);
        }   
        cout << get(1, 1, n, 1, n);
    }
    int32_t get(int32_t id, int32_t ll, int32_t rr, int32_t l, int32_t r)
    {
        if (ll >= l && rr <= r) return st[id];
        if (rr < l || ll > l) return INT_MIN;
        return max(get(Lcon, l, r), get(Rcon, l, r));
    }
    void update(int32_t id, int32_t ll, int32_t rr, int32_t pos, int32_t val)
    {
        if (ll == rr) {st[id] = max(st[id], val);}
        if (pos <= MID) update(Lcon, pos, val);
        else update(Rcon, pos, val); 
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
};
/***********************************************************/
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
    //code below this line:
    cin >> m >> cc >> k;
    largestIncreasingSubarray l, r;
    fr1(i, k) cin >> l.a[i] >> l.a[i];
    l.bruh(k); r.bruh(k);
    finish();
    return 0;
}
//functions content:
/*
    xây đựng một hàm cal()
    
    công thức qhđ f[i][j] = max(f[i - 1][j], f[i][f - 1]) + a[i][j];
    thử xoá từng ô một -> a[i][j] = 0;cal();
    sắp xếp theo dòng && nếu cùng dòng thì xét theo cột -> dãy con tăng dài nhất => từ O(m * n) -> O(k ^ 2)

    đk cần : L(i) + R(i) - 1 = LIS
    đk đủ : S(L(i))
        FOR(i = 1 -> n)
            if (L[i] + R[i] - 1 == LIS)
                S[L[i]] ++;
        FOR(i = 1 -> n) if (L[i] + R[i] - 1 == LIS && S[L[i]] == 1) ans ++;
*/