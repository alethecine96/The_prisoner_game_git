//
// Created by alessandro on 03/04/19.
//

#ifndef PROJECT_ENUMFILE_H
#define PROJECT_ENUMFILE_H

enum direction: int
{
    down=0,
    left=1,
    right=2,
    up=3
};

enum tile_dimension_hitbox: int
{
   hitbox_big=30,
   hitbox_small=2,
   range=14
};

enum tile_number: int
{
    tile_dimension=32,
    number_walkable_tiles = 8,
    double_tile_dimension=64,
    origin=0,
    grass=97,
    parquet=2,
    door=58,
    tiled_floor=0,
    kitchen_floor=4,
    bath_floor=8,
    shower_floor=64,
    gym_mat=91
};

enum dimension: int
{
    width=40,
    height=36,
    window_width=1600,
    window_height=900,
    game_window_width=1280,
    game_window_height=704
};

enum game_utility_number: int
{
    powerupX=514,
    powerupY=514,
    sight=300
};



#endif //PROJECT_ENUMFILE_H
