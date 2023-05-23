//
// Created by rcott on 23/05/2023.
//

#ifndef DK_REPO_MENU_H
#define DK_REPO_MENU_H


class Menu {
public:
	int selectedItem;
	const char* items[3] = { "Reprendre", "Nouvelle partie", "Quitter" };

	Menu() : selectedItem(0) {}

	void update() {
		if (gb.buttons.repeat(BUTTON_UP, 0)) {
			selectedItem--;
			if (selectedItem < 0) {
				selectedItem = 2;
			}
		}
		if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
			selectedItem++;
			if (selectedItem > 2) {
				selectedItem = 0;
			}
		}
		if (gb.buttons.pressed(BUTTON_A)) {
			switch (selectedItem) {
			case 0:
				// reprendre
				break;
			case 1:
				// nouvelle partie
				break;
			case 2:
				// quitter
				break;
			}
		}
	}

	void draw() {
		for (int i = 0; i < 3; i++) {
			if (i == selectedItem) {
				gb.display.setColor(WHITE);
			}
			else {
				gb.display.setColor(GRAY);
			}
			gb.display.println(items[i]);
		}
	}
};

Menu menu;
bool menuOpen = false;

void loop() {
	gb.waitForUpdate();
	gb.display.clear();

	if (gb.buttons.pressed(BUTTON_MENU)) {
		menuOpen = !menuOpen;
	}

	if (menuOpen) {
		menu.update();
		menu.draw();
	}
	else {
		// votre code de jeu ici...
	}
}

};


#endif //DK_REPO_MENU_H
