#include "Fonts.h"
#include "Types.h"
#include "Text.h"
#include <string.h>
#include <stdlib.h>

struct Text *text_create(int x, int y, char content[], int font_size, int font_space, int font_colour)
{
	struct Text *text = malloc(sizeof(struct Text));
	if (text == NULL)
		return NULL;

	//copy the content string
	int length = strlen(content);
	text->content = malloc((length + 1) * sizeof(char));
	if (text->content == NULL) {
		free(text);
		return NULL;
	}
	strcpy(text->content, content);

	text->x = (uint16_t)x;
	text->y = (uint16_t)y;
	text->font_space = (uint16_t)font_space;
	text->font_size = (uint8_t)font_size;
	text->font_colour = (uint8_t)font_colour;
	
	return text;
}

int text_set_content(struct Text *text, char content[])
{
	int length = strlen(content);
	char *copy = malloc((length + 1) * sizeof (char));
	if (copy == NULL) {
		return 0;
	}
	strcpy(copy, content);

	//free the old content
	free(text->content);
	//replace with the new one
	text->content = copy;

	return 1;
}

void text_destroy(struct Text *text)
{
	if(text && text->content) {
		free(text->content);
		free(text);
	}
	return;
}

void text_draw(struct Text *text)
{
	int font_size = text->font_size;
	if (font_size != 5 && font_size != 10 && font_size != 16 && font_size != 22 && font_size != 38)
		font_size = 10;

	print_string(text->x, text->y, font_size, text->font_space, text->font_colour,
		text->content, strlen(text->content), 0, 0);
}

