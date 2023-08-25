#include "elevation/entity/results.h"

#include <iomanip>
#include <iostream>
#include <nlohmann/json-schema.hpp>

namespace fs = std::filesystem;

namespace elevation::data {

static nlohmann::json person_schema = R"(
{
    "$defs": {
        "Player": {
            "properties": {
                "max_life_points": {
                    "title": "Max Life Points",
                    "type": "integer"
                },
                "money": {
                    "title": "Money",
                    "type": "integer"
                },
                "nb_level_suceeded": {
                    "title": "Nb Level Suceeded",
                    "type": "integer"
                },
                "nb_life_points": {
                    "title": "Nb Life Points",
                    "type": "integer"
                },
                "pseudo": {
                    "title": "Pseudo",
                    "type": "string"
                },
                "weapons": {
                    "items": {
                        "$ref": "#/$defs/Weapon"
                    },
                    "title": "Weapons",
                    "type": "array"
                }
            },
            "required": [
                "max_life_points",
                "money",
                "nb_level_suceeded",
                "nb_life_points",
                "pseudo",
                "weapons"
            ],
            "title": "Player",
            "type": "object"
        },
        "Type": {
            "enum": [
                -1,
                0,
                1,
                2
            ],
            "title": "Type",
            "type": "integer"
        },
        "Weapon": {
            "properties": {
                "durability": {
                    "title": "Durability",
                    "type": "integer"
                },
                "durability_loose_per_use": {
                    "title": "Durability Loose Per Use",
                    "type": "integer"
                },
                "name": {
                    "title": "Name",
                    "type": "string"
                },
                "nb_damage": {
                    "title": "Nb Damage",
                    "type": "integer"
                },
                "statement": {
                    "title": "Statement",
                    "type": "string"
                },
                "type": {
                    "$ref": "#/$defs/Type"
                }
            },
            "required": [
                "durability",
                "durability_loose_per_use",
                "name",
                "nb_damage",
                "statement",
                "type"
            ],
            "title": "Weapon",
            "type": "object"
        }
    },
    "properties": {
        "game_id": {
            "format": "uuid",
            "title": "Game Id",
            "type": "string"
        },
        "player": {
            "$ref": "#/$defs/Player"
        }
    },
    "required": [
        "game_id",
        "player"
    ],
    "title": "Result",
    "type": "object"
}

)"_json;

std::vector<std::tuple<std::string, std::string, int>>
create_load_game_statements() {
  fs::create_directories(RESULTS_PATH);

  std::vector<std::tuple<std::string, std::string, int>> vec;

  for (const auto& dir_entry : fs::directory_iterator{RESULTS_PATH}) {
    if (dir_entry.is_regular_file() and
        dir_entry.path().extension() == ".json") {
      const auto jsonObject = data::read_json_file(dir_entry.path());

      nlohmann::json_schema::json_validator validator;  // create validator

      validator.set_root_schema(person_schema);  // insert root-schema

      validator.validate(jsonObject);

      vec.push_back(std::tuple{jsonObject["game_id"],
                               jsonObject["player"]["pseudo"],
                               jsonObject["player"]["nb_level_suceeded"]});
    }
  }

  return vec;
}

void save(const std::string& id, const entity::Player& player) {
  nlohmann::json json{{"game_id", id}, {"player", player.write()}};

  fs::path path = RESULTS_PATH / fmt::format("{}.json", id);

  std::ofstream file{path};
  file.clear();
  file << std::setw(4) << json;
  file.close();
}

nlohmann::json get_saved_data(const std::string& id) {
  return data::read_json_file(RESULTS_PATH / fmt::format("{}.json", id));
}

bool is_new_game(const std::string& id) {
  return not fs::exists(RESULTS_PATH / fmt::format("{}.json", id));
}
}  // namespace elevation::data
