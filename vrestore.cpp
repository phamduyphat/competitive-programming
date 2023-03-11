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

/***********************************************************/
//#define task "vrestore"
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
    
    //code below this line:

#ifndef task
    finish();
#endif
    return 0;
}
//Functions content:
/*
    S(0) = a(0) + a(1)
    S(1) = a(0) + a(2)
    ==> nếu biết a(0) sẽ biết a(1), a(2)
        loại bỏ khỏi S: a(0) + a(1), a(0) + a(2), a(1) + a(2);
    => phần tử bé nhất trong S: a(0) + a(3);
    loại bỏ a(3) + a(0), a(3) + a(1), a(3) + a(2) 
        => a(4);


    KL: nếu bt a(0) thì xđ được a(i);

    thử từng a(0) = v v nhỏ nhất sinh được dãy X
    xét series a(0) + a(1), a(0) + a(2), .. , a(0) + a(n - 1), a(1) + a(2);
    => a(1) + a(2) phải xuất hiện trong số n phần tử nhỏ nhất của S
    s(2) -> s(n - 1) nếu (S(0) + S(1) - S(i) % == 0)


    S: khai báo multi_set 500^2 --> quá chậm;

    => lưu một cái S.dell -> môi lần erase thì đẩy vào S.dell
    bool gen (v) 
    {
        //trả về ok / 0;
        a(0) = v;
        for(int32_t i = 0; i < n; ++ i)
        {
            t = *s.begin();
            a[i] = t - v;
            với mọi j < i : nếu tổng a[i] + a[j] ko có -> return false;
                            S.erase(a[i] + a[j]);
        }

        return true;
        
    }
*/