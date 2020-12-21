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
constexpr auto MESSAGE_WIDTH = 600;
constexpr auto MESSAGE_HEIGHT = 400;
constexpr auto MESSAGE_LOC_HEIGHT = WINDOW_HEIGHT / 2 - MESSAGE_HEIGHT;
constexpr auto MESSAGE_LOC_WIDTH = WINDOW_WIDTH / 2 - MESSAGE_WIDTH;
constexpr auto MENU_HEIGHT = WINDOW_HEIGHT;
constexpr auto MENU_WIDTH = WINDOW_WIDTH / 10;
constexpr auto BOARD_HEIGHT = WINDOW_HEIGHT;
constexpr auto BOARD_WIDTH = WINDOW_WIDTH - MENU_WIDTH;

//========================== saving map's file path ===========================
constexpr auto BOARD_PATH = "Board.txt";