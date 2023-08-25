from __future__ import annotations

from pydantic import BaseModel
from enum import Enum

from uuid import UUID


class Result(BaseModel):
    game_id: UUID
    player: Player


class Player(BaseModel):
    max_life_points: int
    money: int
    nb_level_suceeded: int
    nb_life_points: int
    pseudo: str
    weapons: list[Weapon]


class Weapon(BaseModel):
    durability: int
    durability_loose_per_use: int
    name: str
    nb_damage: int
    statement: str
    type: Type


class Type(Enum):
    no_weapon = -1
    fist = 0
    melee_weapon = 1
    fire_arm = 2
