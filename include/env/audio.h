#pragma once

#include <stdbool.h>
#include <stdint.h>

uint32_t
audioCreate();
void
audioDelete(uint32_t id);
void
audioPlay(uint32_t id);
void
audioStop(uint32_t id);
void
audioSet3d(uint32_t id, bool is3d);
void
audioSetLoop(uint32_t id, bool loop);
void
audioSetPosition(uint32_t id, float x, float y, float z);
void
audioSetBuffer(uint32_t id, uint32_t buffid);