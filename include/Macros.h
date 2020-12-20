#pragma once
//========================== game objects symbols ============================
constexpr auto MAX_NUM_OF_ITEMS = 10;
constexpr auto PLAYER = '@';
constexpr auto NOTHING = ' ';
constexpr auto ENEMY = '%';
constexpr auto LADDER = 'H';
constexpr auto ROD = '-';
constexpr auto WALL = '#';
constexpr auto COIN = '*';
constexpr auto SAVE = 's';
constexpr auto DELETE = 'd';
constexpr auto CLEAR = 'c';
constexpr auto MENU = 'm';

//=========================== Window's parameters ============================
constexpr auto WINDOW_HEIGHT = 1000;
constexpr auto WINDOW_WIDTH = 1800;
#define MENU_HEIGHT WINDOW_HEIGHT
#define MENU_WIDTH WINDOW_WIDTH/10
#define BOARD_HEIGHT WINDOW_HEIGHT
#define BOARD_WIDTH WINDOW_WIDTH - MENU_WIDTH

//========================== saving map's file path ===========================
constexpr auto BOARD_PATH = "Board.txt";