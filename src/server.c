/**************************************************************************
*
* Tint2 panel
*
* Copyright (C) 2007 Pål Staurland (staura@gmail.com)
* Modified (C) 2008 thierry lorthiois (lorthiois@bbsoft.fr)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "server.h"
#include "task.h"
#include "window.h"

void server_catch_error (Display *d, XErrorEvent *ev){}

static char *name_trayer = 0;


void server_init_atoms ()
{
   server.atom._XROOTPMAP_ID = XInternAtom (server.dsp, "_XROOTPMAP_ID", False);
   server.atom._NET_CURRENT_DESKTOP = XInternAtom (server.dsp, "_NET_CURRENT_DESKTOP", False);
   server.atom._NET_NUMBER_OF_DESKTOPS = XInternAtom (server.dsp, "_NET_NUMBER_OF_DESKTOPS", False);
   server.atom._NET_DESKTOP_GEOMETRY = XInternAtom (server.dsp, "_NET_DESKTOP_GEOMETRY", False);
   server.atom._NET_DESKTOP_VIEWPORT = XInternAtom (server.dsp, "_NET_DESKTOP_VIEWPORT", False);
   server.atom._NET_ACTIVE_WINDOW = XInternAtom (server.dsp, "_NET_ACTIVE_WINDOW", False);
   server.atom._NET_WM_WINDOW_TYPE = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE", False);
   server.atom._NET_WM_STATE_SKIP_PAGER = XInternAtom (server.dsp, "_NET_WM_STATE_SKIP_PAGER", False);
   server.atom._NET_WM_STATE_SKIP_TASKBAR = XInternAtom (server.dsp, "_NET_WM_STATE_SKIP_TASKBAR", False);
   server.atom._NET_WM_STATE_STICKY = XInternAtom (server.dsp, "_NET_WM_STATE_STICKY", False);
   server.atom._NET_WM_STATE_DEMANDS_ATTENTION = XInternAtom (server.dsp, "_NET_WM_STATE_DEMANDS_ATTENTION", False);
   server.atom._NET_WM_WINDOW_TYPE_DOCK = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_DOCK", False);
   server.atom._NET_WM_WINDOW_TYPE_DESKTOP = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_DESKTOP", False);
   server.atom._NET_WM_WINDOW_TYPE_TOOLBAR = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_TOOLBAR", False);
   server.atom._NET_WM_WINDOW_TYPE_MENU = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_MENU", False);
   server.atom._NET_WM_WINDOW_TYPE_SPLASH = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_SPLASH", False);
   server.atom._NET_WM_WINDOW_TYPE_DIALOG = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_DIALOG", False);
   server.atom._NET_WM_WINDOW_TYPE_NORMAL = XInternAtom (server.dsp, "_NET_WM_WINDOW_TYPE_NORMAL", False);
   server.atom._NET_WM_DESKTOP = XInternAtom (server.dsp, "_NET_WM_DESKTOP", False);
   server.atom.WM_STATE = XInternAtom (server.dsp, "WM_STATE", False);
   server.atom._NET_WM_STATE = XInternAtom (server.dsp, "_NET_WM_STATE", False);
   server.atom._NET_WM_STATE_MAXIMIZED_VERT = XInternAtom (server.dsp, "_NET_WM_STATE_MAXIMIZED_VERT", False);
   server.atom._NET_WM_STATE_MAXIMIZED_HORZ = XInternAtom (server.dsp, "_NET_WM_STATE_MAXIMIZED_HORZ", False);
   server.atom._NET_WM_STATE_SHADED = XInternAtom (server.dsp, "_NET_WM_STATE_SHADED", False);
   server.atom._NET_WM_STATE_BELOW = XInternAtom (server.dsp, "_NET_WM_STATE_BELOW", False);
   server.atom._NET_WM_STATE_MODAL = XInternAtom (server.dsp, "_NET_WM_STATE_MODAL", False);
   server.atom._NET_CLIENT_LIST = XInternAtom (server.dsp, "_NET_CLIENT_LIST", False);
   server.atom._NET_WM_VISIBLE_NAME = XInternAtom (server.dsp, "_NET_WM_VISIBLE_NAME", False);
   server.atom._NET_WM_NAME = XInternAtom (server.dsp, "_NET_WM_NAME", False);
   server.atom._NET_WM_STRUT = XInternAtom (server.dsp, "_NET_WM_STRUT", False);
   server.atom._NET_WM_ICON = XInternAtom (server.dsp, "_NET_WM_ICON", False);
   server.atom._NET_CLOSE_WINDOW = XInternAtom (server.dsp, "_NET_CLOSE_WINDOW", False);
   server.atom.UTF8_STRING = XInternAtom (server.dsp, "UTF8_STRING", False);
   server.atom._NET_SUPPORTING_WM_CHECK = XInternAtom (server.dsp, "_NET_SUPPORTING_WM_CHECK", False);
   server.atom._NET_SUPPORTING_WM_CHECK = XInternAtom (server.dsp, "_NET_WM_NAME", False);
   server.atom._WIN_LAYER = XInternAtom (server.dsp, "_WIN_LAYER", False);
   server.atom._NET_WM_STRUT_PARTIAL = XInternAtom (server.dsp, "_NET_WM_STRUT_PARTIAL", False);
   server.atom.WM_NAME = XInternAtom(server.dsp, "WM_NAME", False);
   server.atom.__SWM_VROOT = XInternAtom(server.dsp, "__SWM_VROOT", False);
   server.atom._MOTIF_WM_HINTS = XInternAtom(server.dsp, "_MOTIF_WM_HINTS", False);

	// systray protocol
	name_trayer = g_strdup_printf("_NET_SYSTEM_TRAY_S%d", DefaultScreen(server.dsp));
	server.atom._NET_SYSTEM_TRAY_SCREEN = XInternAtom(server.dsp, name_trayer, False);
	server.atom._NET_SYSTEM_TRAY_OPCODE = XInternAtom(server.dsp, "_NET_SYSTEM_TRAY_OPCODE", False);
	server.atom.MANAGER = XInternAtom(server.dsp, "MANAGER", False);
	server.atom._NET_SYSTEM_TRAY_MESSAGE_DATA = XInternAtom(server.dsp, "_NET_SYSTEM_TRAY_MESSAGE_DATA", False);
	server.atom._NET_SYSTEM_TRAY_ORIENTATION = XInternAtom(server.dsp, "_NET_SYSTEM_TRAY_ORIENTATION", False);
	server.atom._XEMBED = XInternAtom(server.dsp, "_XEMBED", False);
	server.atom._XEMBED_INFO = XInternAtom(server.dsp, "_XEMBED_INFO", False);
}


void cleanup_server()
{
	if (name_trayer) free(name_trayer);
}


void send_event32 (Window win, Atom at, long data1, long data2, long data3)
{
   XEvent event;

   event.xclient.type = ClientMessage;
   event.xclient.serial = 0;
   event.xclient.send_event = True;
   event.xclient.display = server.dsp;
   event.xclient.window = win;
   event.xclient.message_type = at;

   event.xclient.format = 32;
   event.xclient.data.l[0] = data1;
   event.xclient.data.l[1] = data2;
   event.xclient.data.l[2] = data3;
   event.xclient.data.l[3] = 0;
   event.xclient.data.l[4] = 0;

   XSendEvent(server.dsp, server.root_win, False, SubstructureRedirectMask|SubstructureNotifyMask, &event);
}


int get_property32 (Window win, Atom at, Atom type)
{
   Atom type_ret;
   int format_ret = 0, data = 0;
   unsigned long nitems_ret = 0;
   unsigned long bafter_ret = 0;
   unsigned char *prop_value = 0;
   int result;

   if (!win) return 0;

   result = XGetWindowProperty(server.dsp, win, at, 0, 0x7fffffff, False, type, &type_ret, &format_ret, &nitems_ret, &bafter_ret, &prop_value);

   if (result == Success && prop_value) {
      data = ((gulong*)prop_value)[0];
      XFree (prop_value);
   }
   return data;
}


void *server_get_property (Window win, Atom at, Atom type, int *num_results)
{
   Atom type_ret;
   int format_ret = 0;
   unsigned long nitems_ret = 0;
   unsigned long bafter_ret = 0;
   unsigned char *prop_value;
   int result;

   if (!win) return 0;

   result = XGetWindowProperty(server.dsp, win, at, 0, 0x7fffffff, False, type, &type_ret, &format_ret, &nitems_ret, &bafter_ret, &prop_value);

   /* Send back resultcount */
   if (num_results) *num_results = nitems_ret;

   if (result == Success && prop_value) return prop_value;
   else return 0;
}


void get_root_pixmap()
{
	Pixmap ret = None;

   unsigned long *res;
	int  c = 2;

	do {
		res = server_get_property (server.root_win, server.atom._XROOTPMAP_ID, XA_PIXMAP, 0);
		if (res) {
			ret = *((Pixmap*)res);
			XFree(res);
         break;
		}
	} while (--c > 0);
	server.root_pmap = ret;

	if (server.root_pmap == None)
		fprintf(stderr, "tint2 : pixmap background detection failed\n");
	else {
		XGCValues  gcv;
		gcv.ts_x_origin = 0;
		gcv.ts_y_origin = 0;
		gcv.fill_style = FillTiled;
		uint mask = GCTileStipXOrigin | GCTileStipYOrigin | GCFillStyle | GCTile;

		gcv.tile = server.root_pmap;
		XChangeGC(server.dsp, server.gc, mask, &gcv);
	}
}


int compareMonitor(const void *monitor1, const void *monitor2)
{
   Monitor *m1 = (Monitor*)monitor1;
   Monitor *m2 = (Monitor*)monitor2;

   if (m1->x < m2->x) {
      return -1;
   }
   else
      if (m1->x > m2->x) {
         return 1;
      }
      else
         if (m1->width < m2->width) {
            return 1;
         }
         else
            if (m1->width > m2->width) {
               return -1;
            }
            else {
               return 0;
            }
}


void get_monitors_and_desktops()
{
   int i;

   if (server.monitor) free(server.monitor);
   server.nb_monitor = 0;
   server.monitor = 0;

   int nb_monitor;
   if (XineramaIsActive(server.dsp)) {
      XineramaScreenInfo *info = XineramaQueryScreens(server.dsp, &nb_monitor);

      if (info) {
			int nb=0, j;

         i = 0;
         server.monitor = calloc(nb_monitor, sizeof(Monitor));
         while (i < nb_monitor) {
	         for (j = 0; j < i; j++) {
					if (info[i].x_org >= info[j].x_org && info[i].y_org >= info[j].y_org && (info[i].x_org+info[i].width) <= (info[j].x_org+info[j].width) && (info[i].y_org+info[i].height) <= (info[j].y_org+info[j].height)) {
						if (info[i].x_org == info[j].x_org && info[i].y_org == info[j].y_org && info[i].width == info[j].width && info[i].height == info[j].height && nb == 0) {
							// add the first monitor
							break;
						}
						else {
							// doesn't count monitor 'i' because it's included into another one
				       	//fprintf(stderr, "monitor %d included into another one\n", i);
			       		goto next;
						}
					}
				}

            server.monitor[nb].x = info[i].x_org;
            server.monitor[nb].y = info[i].y_org;
            server.monitor[nb].width = info[i].width;
            server.monitor[nb].height = info[i].height;
				nb++;
next:
				i++;
         }
         XFree(info);
         server.nb_monitor = nb;

         // ordered monitor according to coordinate
         qsort(server.monitor, server.nb_monitor, sizeof(Monitor), compareMonitor);
      }
   }

   if (!server.nb_monitor) {
      server.nb_monitor = 1;
      server.monitor = calloc(server.nb_monitor, sizeof(Monitor));
      server.monitor[0].x = server.monitor[0].y = 0;
      server.monitor[0].width = DisplayWidth (server.dsp, server.screen);
      server.monitor[0].height = DisplayHeight (server.dsp, server.screen);
   }

	// detect number of desktops
	// wait 15s to leave some time for window manager startup
   for (i=0 ; i < 15 ; i++) {
      server.nb_desktop = server_get_number_of_desktop ();
      if (server.nb_desktop > 0) break;
      sleep(1);
   }
   if (server.nb_desktop == 0) {
      server.nb_desktop = 1;
      fprintf(stderr, "warning : WM doesn't respect NETWM specs. tint2 default to 1 desktop.\n");
   }
  	fprintf(stderr, "tint2 : nb monitor %d, nb desktop %d\n", server.nb_monitor, server.nb_desktop);
}

