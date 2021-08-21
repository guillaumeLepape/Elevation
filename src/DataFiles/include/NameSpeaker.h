#ifndef NAME_SPEAKER_H
#define NAME_SPEAKER_H

#include <string>
#include <tuple>
#include <vector>

enum class NameSpeaker { player = 0, plug, description, action };

typedef std::vector<std::tuple<NameSpeaker, std::string>> Message;

#endif