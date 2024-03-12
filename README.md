## CommandMenu

### Features
- UP and DOWN arrows for navigating through items.
- LEFT and RIGHT arrows for change item values (toggles and sliders).
- TAB key to cycle through tabs.
- Focus-aware input handling.

### Example Usage
```cpp
#include "CommandMenu.h"

int main() {
    CommandMenu::Menu menu;
    // Begin the tabs.
    auto mainTab = std::make_unique<CommandMenu::Tab>("Main");
	auto settingsTab = std::make_unique<CommandMenu::Tab>("Settings");

    // Main tab contents.
    mainTab->AddElement(std::make_unique<CommandMenu::Toggle>("Feature One", false));
	mainTab->AddElement(std::make_unique<CommandMenu::Toggle>("Feature Two", false));
    // Settings tab contents.
    settingsTab->AddElement(std::make_unique<CommandMenu::SliderInt>("FPS", 60, 30, 240, 30));
	settingsTab->AddElement(std::make_unique<CommandMenu::SliderInt>("Brightness", 20, 0, 100, 10));
    
    // End the tabs.
    menu.AddTab(std::move(mainTab));
	menu.AddTab(std::move(settingsTab));
    // Display the menu.
	menu.Display();

    while (true) {
        // Receive inputs.
        menu.ProcessInput();
    }
}
```

### Building
Ensure that all header and source files are compiled and linked to your project.
