
#ifndef PROPERTIES
#define PROPERTIES

#include <gtk/gtk.h>

// panel
GtkWidget  *panel_width, *panel_height, *panel_margin_x, *panel_margin_y, *panel_padding_x, *panel_padding_y, *panel_spacing;
GtkWidget  *panel_wm_menu, *panel_dock, *panel_autohide, *panel_autohide_show_time, *panel_autohide_hide_time, *panel_autohide_size;
GtkWidget  *panel_combo_strut_policy, *panel_combo_layer, *panel_combo_width_type, *panel_combo_height_type, *panel_combo_monitor;
GtkWidget  *items_order;

// taskbar
GtkWidget  *taskbar_show_desktop, *taskbar_show_name, *taskbar_padding_x, *taskbar_padding_y, *taskbar_spacing;
GtkWidget  *taskbar_name_padding_x, *taskbar_name_inactive_color, *taskbar_name_active_color, *taskbar_name_font;

// task

// clock
GtkWidget  *clock_format_line1, *clock_format_line2, *clock_format_tooltip, *clock_tmz_line1, *clock_tmz_line2, *clock_tmz_tooltip;
GtkWidget  *clock_left_command, *clock_right_command;
GtkWidget  *clock_padding_x, *clock_padding_y, *clock_font_line1, *clock_font_line2, *clock_font_color;

// battery
GtkWidget  *battery_hide_if_higher, *battery_alert_if_lower, *battery_alert_cmd;
GtkWidget  *battery_padding_x, *battery_padding_y, *battery_font_line1, *battery_font_line2, *battery_font_color;

// systray
GtkWidget  *systray_icon_order, *systray_padding_x, *systray_padding_y, *systray_spacing;
GtkWidget  *systray_icon_size, *systray_icon_opacity, *systray_icon_saturation, *systray_icon_brightness;

// tooltip

// launcher

// background
GtkWidget  *combo_background;
GtkWidget  *margin_x, *margin_y;

GtkWidget *create_properties();


#endif

