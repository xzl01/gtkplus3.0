/* Generated by wayland-scanner 1.19.0 */

/*
 * Copyright © 2012, 2013 Intel Corporation
 * Copyright © 2015, 2016 Jan Arne Petersen
 * Copyright © 2017, 2018 Red Hat, Inc.
 * Copyright © 2018       Purism SPC
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 */

#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

#ifndef __has_attribute
# define __has_attribute(x) 0  /* Compatibility with non-clang compilers. */
#endif

#if (__has_attribute(visibility) || defined(__GNUC__) && __GNUC__ >= 4)
#define WL_PRIVATE __attribute__ ((visibility("hidden")))
#else
#define WL_PRIVATE
#endif

extern const struct wl_interface wl_seat_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface zwp_text_input_v3_interface;

static const struct wl_interface *text_input_unstable_v3_types[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	&wl_surface_interface,
	&wl_surface_interface,
	&zwp_text_input_v3_interface,
	&wl_seat_interface,
};

static const struct wl_message zwp_text_input_v3_requests[] = {
	{ "destroy", "", text_input_unstable_v3_types + 0 },
	{ "enable", "", text_input_unstable_v3_types + 0 },
	{ "disable", "", text_input_unstable_v3_types + 0 },
	{ "set_surrounding_text", "sii", text_input_unstable_v3_types + 0 },
	{ "set_text_change_cause", "u", text_input_unstable_v3_types + 0 },
	{ "set_content_type", "uu", text_input_unstable_v3_types + 0 },
	{ "set_cursor_rectangle", "iiii", text_input_unstable_v3_types + 0 },
	{ "commit", "", text_input_unstable_v3_types + 0 },
};

static const struct wl_message zwp_text_input_v3_events[] = {
	{ "enter", "o", text_input_unstable_v3_types + 4 },
	{ "leave", "o", text_input_unstable_v3_types + 5 },
	{ "preedit_string", "?sii", text_input_unstable_v3_types + 0 },
	{ "commit_string", "?s", text_input_unstable_v3_types + 0 },
	{ "delete_surrounding_text", "uu", text_input_unstable_v3_types + 0 },
	{ "done", "u", text_input_unstable_v3_types + 0 },
};

WL_PRIVATE const struct wl_interface zwp_text_input_v3_interface = {
	"zwp_text_input_v3", 1,
	8, zwp_text_input_v3_requests,
	6, zwp_text_input_v3_events,
};

static const struct wl_message zwp_text_input_manager_v3_requests[] = {
	{ "destroy", "", text_input_unstable_v3_types + 0 },
	{ "get_text_input", "no", text_input_unstable_v3_types + 6 },
};

WL_PRIVATE const struct wl_interface zwp_text_input_manager_v3_interface = {
	"zwp_text_input_manager_v3", 1,
	2, zwp_text_input_manager_v3_requests,
	0, NULL,
};

