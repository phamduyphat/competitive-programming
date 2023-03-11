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
//Global variables below this line:

/***********************************************************/
//Functions declarations:
int8_t check (string &s, vector<pair<char, char>> &a)
{
    for(int32_t ll = 0, rr = s.size() - 1; ll <= rr; ll ++, rr --)
    {
        if (s[ll] != s[rr])
        {
            a.pb({max(s[ll], s[rr]), min(s[ll], s[rr])});
        }
        if (a.size() >= 3)
            return -1;
    }
    if (a.empty()) return 3;
    return a.size();
}
void solve(string &s)
{
    vector<pair<char, char>> unmatched_cases;
    int32_t temp = check(s, unmatched_cases);
    if (temp == -1)
        cout << "NO";
    elif (temp == 1)
    {
        if (s.size() % 2 == 1)
        {
            if (s[s.size() / 2] != unmatched_cases[0].fi && s[s.size() / 2] != unmatched_cases[0].se) cout << "NO";
            else cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    elif (temp == 2)
    {
        if ((unmatched_cases[0].fi == unmatched_cases[1].fi && unmatched_cases[0].se == unmatched_cases[1].se) || (unmatched_cases[0].fi == unmatched_cases[1].se && unmatched_cases[0].se == unmatched_cases[1].fi))
        {
            cout << "YES";
        }
        else 
            cout << "NO";
    }
    elif (temp == 3)
    {
        cout << "YES";
    }
    cout << endline;
}
/***********************************************************/
//#define task "swapalin"
driver main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef task
    freopen (task".inp", "r", stdin);
    freopen (task".out", "w", stdout);
#else
    freopen ("input.inp","r",stdin);
    freopen ("output.out","w",stdout);
#endif
    //Local variables below this line:
    string s;

    //code below this line:
    while (cin >> s)
    {
        solve(s);
    }
#ifndef task
    finish();
#endif
    return 0;
}
//Functions content:
