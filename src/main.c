#include <pebble.h>
	
Window *my_window;
TextLayer *my_text_layer;

void select_click_handler(ClickRecognizerRef recognizer, void *context) {
		vibes_short_pulse();
		int pia = rand() % 4;
		if(pia == 0)
                text_layer_set_text(my_text_layer, "SÖRT");
		else if(pia == 1)
                text_layer_set_text(my_text_layer, "BORT");
		else if(pia == 2)
                text_layer_set_text(my_text_layer, "PÁLINKÁT");
		else if(pia == 3)
                text_layer_set_text(my_text_layer, "KOKTÉLT");
		else if(pia == 4)
                text_layer_set_text(my_text_layer, "PEZSGŐT");
}

void click_config_provider(void *context) {
        window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

void window_load(Window *my_window) {
	// Itt adunk tartalmat az ablaknak.
	my_text_layer = text_layer_create(GRect(0, 55, 144, 38));
	text_layer_set_background_color(my_text_layer, GColorBlack);
	text_layer_set_text_color(my_text_layer, GColorWhite);
	text_layer_set_text_alignment(my_text_layer, GTextAlignmentCenter);
	text_layer_set_font(my_text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));

	layer_add_child(window_get_root_layer(my_window), (Layer*) my_text_layer);
	text_layer_set_text(my_text_layer, "Mit igyak?");
}

void window_unload(Window *my_window) {
	// Itt szabadítjuk fel a memóriát az ablakban.
	text_layer_destroy(my_text_layer);
}

void init() {
	// Itt inicializáljuk az appot.
	my_window = window_create();
	window_set_window_handlers(my_window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	
	window_set_click_config_provider(my_window, click_config_provider);
	window_stack_push(my_window, true);
}

void deinit() {
	// Itt deinicializáljuk az appot.
	window_destroy(my_window);
}
	
int main(void) {
	init();
	app_event_loop();
	deinit();
}