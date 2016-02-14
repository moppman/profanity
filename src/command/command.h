/*
 * command.h
 *
 * Copyright (C) 2012 - 2016 James Booth <boothj5@gmail.com>
 *
 * This file is part of Profanity.
 *
 * Profanity is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Profanity is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Profanity.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link the code of portions of this program with the OpenSSL library under
 * certain conditions as described in each individual source file, and
 * distribute linked combinations including the two.
 *
 * You must obey the GNU General Public License in all respects for all of the
 * code used other than OpenSSL. If you modify file(s) with this exception, you
 * may extend this exception to your version of the file(s), but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version. If you delete this exception statement from all
 * source files in the program, then also delete it here.
 *
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <glib.h>

#include "xmpp/form.h"
#include "ui/ui.h"

GHashTable *commands;

void cmd_init(void);
void cmd_uninit(void);

char* cmd_autocomplete(ProfWin *window, const char *const input);
void cmd_reset_autocomplete(ProfWin *window);
void cmd_autocomplete_add(const char * const value);
void cmd_autocomplete_remove(const char * const value);
void cmd_autocomplete_add_form_fields(DataForm *form);
void cmd_autocomplete_remove_form_fields(DataForm *form);
void cmd_alias_add(char *value);
void cmd_alias_remove(char *value);

gboolean cmd_valid_tag(const char *const str);
gboolean cmd_has_tag(Command *pcmd, const char *const tag);

gboolean cmd_process_input(ProfWin *window, char *inp);
void cmd_execute_connect(ProfWin *window, const char *const account);

gboolean cmd_exists(char *cmd);

GSList* cmd_get_basic_help(void);
GSList* cmd_get_settings_help(void);
GSList* cmd_get_presence_help(void);

void cmd_history_append(char *inp);
char* cmd_history_previous(char *inp);
char* cmd_history_next(char *inp);

void command_docgen(void);

#endif
