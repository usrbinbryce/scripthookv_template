#include "script.h"

/**
 * Called once per frame
 */
void update() {
  // Set text properties
  HUD::SET_TEXT_FONT(0); // Font 0 is the default GTA font
  HUD::SET_TEXT_SCALE(0.5f, 0.5f); // Text size
  HUD::SET_TEXT_COLOUR(255, 255, 255, 255); // White color (R, G, B, Alpha)
  HUD::SET_TEXT_CENTRE(1); // Center the text (0 = left aligned, 1 = centered)
  HUD::SET_TEXT_DROP_SHADOW(); // Add shadow for better visibility
  HUD::SET_TEXT_OUTLINE(); // Add outline for better visibility
  
  // Draw text on screen
  // Coordinates: x=0.5 (center horizontally), y=0.1 (near top), p2=0
  HUD::BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
  HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Hello from the template!");
  HUD::END_TEXT_COMMAND_DISPLAY_TEXT(0.5f, 0.1f, 0);
}

/**
 * Main script logic
 */
int main() {
  while (true) {
    update();
    WAIT(0);
  }
}

/**
 * Main script function. Calls main method
 */
void ScriptMain() { main(); }