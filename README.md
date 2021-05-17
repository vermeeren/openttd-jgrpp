## JGR's Patchpack version 0.41.1

This is a collection of patches applied to [OpenTTD](http://www.openttd.org/)

* * *

OpenTTD is a transport simulation game based upon the popular game Transport
Tycoon Deluxe, written by Chris Sawyer. It attempts to mimic the original
game as closely as possible while extending it with new features.

OpenTTD is licensed under the GNU General Public License version 2.0,
but includes some 3rd party software under different licenses. See the
section "Licensing" below for details,

* * *

See [below](#openttd) for the original OpenTTD readme.

The thread for this patchpack can be found [here](http://www.tt-forums.net/viewtopic.php?f=33&t=73469).

See [jgrpp-changelog.md](jgrpp-changelog.md) for changelog.

See the [wiki](https://github.com/JGRennison/OpenTTD-patches/wiki) for guides on how to use some of the included features.

See [installation.md](/installation.md) for instructions on how to install.

(Nearly all of the patches which are listed below have been modified, fixed or extended in some way, and so are not the same as the originals which are linked).

#### Railways and Trains

* Drive-through train depots.
* [Template-based train replacement](http://www.tt-forums.net/viewtopic.php?f=33&t=58904).
* [Routing restrictions](http://www.tt-forums.net/viewtopic.php?f=33&t=73397).  
  This also includes slots and counters.  
  See the [guide on the wiki](https://github.com/JGRennison/OpenTTD-patches/wiki/Signalling) for more information.
* [Programmable pre-signals](http://www.tt-forums.net/viewtopic.php?f=33&t=47690).  
  These are not shown in the build signal window by default.  
  See the [guide on the wiki](https://github.com/JGRennison/OpenTTD-patches/wiki/Signalling) for more information.
* Freight train through load.  
  This is an alternative loading mode for freight trains for the case where the train is longer then the platform.
* Multiple rail types per tile.
* [Polyline rail track building tool](http://www.tt-forums.net/viewtopic.php?f=33&t=57080).
* Add news setting for trains waiting due to routing restrictions.
* Add setting to enable flipping direction of all train types in depot.
* Realistic train braking.  
  In this mode, trains have a stopping distance and will reserve ahead accordingly, trains cannot stop instantly.  
  See the [guide on the wiki](https://github.com/JGRennison/OpenTTD-patches/wiki/Realistic-braking) for more information.
* Allow converting track type under trains when compatible with the new rail type.

#### Roads and Road Vehicles

* One-way road and road vehicle overtaking enhancements.  
  See the [wiki](https://github.com/JGRennison/OpenTTD-patches/wiki/One-way-roads) for full details.
* Add setting to allow articulated road vehicles to overtake other vehicles.
* Add setting to control road vehicle re-routing on road layout changes.
* Disallow ordering ordinary road vehicles to tram depots and vice versa.
* Improve road vehicle pathfinding when multiple vehicles are simultaneously heading to a station with multiple bay/stop entrances.
* Add setting for default road/tram types.

#### Level Crossings

* [Close adjacent level crossings](http://www.tt-forums.net/viewtopic.php?p=836749).
* Prevent road vehicles from being stopped on level crossings.
* Add setting to enable improved level crossing safety.
* Trains break down after colliding with a road vehicle.

#### Bridges and Tunnels

* Signals in tunnels and on bridges.
* Custom bridge heads.
* [Chunnels (tunnels under bodies of water)](https://www.tt-forums.net/viewtopic.php?f=33&t=41775). Off by default.
* Allow building rail stations under bridges, subject to height/clearance and bridge pillar limitations.
* Add setting to allow placing NewGRF rail stations under bridges, when the GRF doesn't specify whether or not it can be placed under bridges.
* Add setting to allow placing all NewGRF objects under bridges, even when it would not otherwise be allowed by the GRF.
* Add setting to allow placing road/tram stops under bridges.
* Add setting to allow placing docks under bridges.
* Vehicles visible in tunnels (transparency setting).

#### Airports

* [Upgrade airports](http://www.tt-forums.net/viewtopic.php?f=33&t=35867).

#### Ships

* [Ship collision avoidance](http://www.tt-forums.net/viewtopic.php?f=33&t=74365).

#### Vehicles in General

* [Improved breakdowns](http://www.tt-forums.net/viewtopic.php?f=33&t=39518).
* [Vehicle repair cost setting](http://www.tt-forums.net/viewtopic.php?f=33&t=45642).
* Send vehicles which need auto-renewing due to age, for servicing, even if breakdowns are off and no servicing if no breakdowns is on.
* Add shift-clicking on vehicle depot button to select specific depot.
* Cargo type filter in vehicle list windows.
* Add client setting for vehicle naming scheme.
* [Vehicle lifetime profit](http://www.tt-forums.net/viewtopic.php?f=33&t=72844).
* Add settings to disable vehicle expiry and introduction after the given years.
* Open train vehicle details window on total cargo tab if shift pressed.
* Add news/advice setting to warn if no depot order in vehicle schedule.
* [Add buttons to collapse/expand all groups](http://www.tt-forums.net/viewtopic.php?f=33&t=74365).
* Add a menu item to the vehicle list to assign all listed vehicles to a new group.
* Add a setting to include the train length and group name in the vehicle details window.
* Add a setting for whether to open the new vehicle GUI when share-cloning.
* Add setting to disable mass action buttons for top-level vehicle lists.

#### Orders and Timetabling

* [Automated timetables and separation](http://www.tt-forums.net/viewtopic.php?f=33&t=46391).
* Allow clearing of timetable time fields which are at 0. Allow explicitly setting timetable time fields to 0 without clearing them.  
* Allow changing/clearing the timetabled waiting time and max speed of all of a vehicle's orders at once.  
* Add client setting to show the remainder ticks in timetable, after dividing to days or minutes.  
* Add a company setting to control the number of ticks used in auto-fill timetable rounding.
* [Cargo type orders](https://www.tt-forums.net/viewtopic.php?p=1047749).  
  This allows order load/unload types to be set per cargo type. (This does work with cargodist).
* Order occupancy.  
  Add column to the orders GUI to show occupancy running average, show the average order occupancy, and add a vehicle sort mode.
* [Timetabling waiting time in depots](http://www.tt-forums.net/viewtopic.php?f=33&t=70969).
* [Scheduled dispatch](https://github.com/innocenat/OpenTTD-patches/tree/scheduled-dispatch-sx).
* [More conditional orders](http://www.tt-forums.net/viewtopic.php?f=33&t=38317).  
  Next station: is cargo waiting, is cargo accepted, number of free platforms, amount of cargo waiting.  
  Percent of times, per-cargo load percentage, current time/date, timetable lateness.  
  Slots/counters: train in slot, slot occupancy, counter value.
* Reverse at waypoint orders.
* Add a menu item to the vehicle list to change order target, e.g. for moving depot orders to a different depot.
* Add game setting to allow only non-stop orders for trains and road vehicles.
* Go to depot and sell vehicle orders.
* Order mode to lock timetable wait and travel times against autofill/automate changes.
* Leave early and leave early if any/all cargoes fully loaded order timetable flags.
* Timetabled wait times at waypoints.
* Add warning/info messages to the timetable window.
* Add features to reverse the order of an order list, and to append the reverse of an order list.  
  (Use the ctrl key when the end of orders marker is selected).
* Add company setting for whether to advance the current order when cloning/copying/sharing (if current depot is in order list).
* Add vehicle list menu item to mass cancel go to or service at depot orders.

#### Stations

* [Departure boards](https://www.tt-forums.net/viewtopic.php?f=33&t=49956).
* Add a setting to increase the station catchment radius.
* Station rating: track "last visited vehicle type" separately per cargo.
* Add setting to scale station cargo capacity and rating tolerance by size.
* Add setting: station rating tolerance to waiting time depends on cargo class.
* Enable vehicle list buttons in station window when the list would be non-empty.
* Enable vehicle group management actions on other companies' stations.
* Add support for allowing/disallowing supply to a station, per cargo, by ctrl-clicking the station cargo rating.
* Add setting to show a company-coloured mark next to vehicles in vehicle list windows, if their owner does not match the list owner.

#### Towns

* [Town cargo generation factor](http://www.tt-forums.net/viewtopic.php?t=46399).
* [Rating in town label](http://www.tt-forums.net/viewtopic.php?f=33&t=42598).
* [Random town road reconstruction](https://www.tt-forums.net/viewtopic.php?f=33&t=36438). This defaults to off.
* Add very and extremely slow options to town growth rate setting.
* Add a setting to scale town growth rate by proportion of town cargo transported.
* Add "indifferent" mode to the town council attitude to area restructuring setting.
* Disallow converting town-owned roads to types with the no houses flag.

#### Industries

* Industry cargo generation factor.

#### Map and Landscaping

* Enable building rivers in game. Off by default.
* Add a setting to [reduce](http://www.tt-forums.net/viewtopic.php?p=890778#p890778) or stop the tree growth rate.
* [Adjusted arctic tree placement](http://www.tt-forums.net/viewtopic.php?f=33&t=72502).
* Add a setting to disable removing sea/rivers.
* Allow building objects by area (1x1 objects only).
* Allow purchasing a region of tiles at once, by dragging.
* Add setting to control if and how land purchasing is permitted.
* Add a company rate limit for land purchasing.
* Add a company rate limit for object construction.
* [Minimum town distance](https://www.tt-forums.net/viewtopic.php?f=33&t=33625).
* Add map generation settings to control river/lake and rocky patch generation.  
* Add settings to customise the size of town zones, and city zones.

#### Scenario Editor

* [Picking and placing single houses in the scenario editor](http://www.tt-forums.net/viewtopic.php?f=33&t=68894).
* Add settings to enable multiple churches/stadiums and to ignore date/zone/GRF when placing houses in the scenario editor.
* [Remove all trees in scenario editor](http://www.tt-forums.net/viewtopic.php?f=33&t=49326).

#### Interface and Visuals

* [Zoning](http://www.tt-forums.net/viewtopic.php?f=33&t=33701).
* [Measurement tools](http://www.tt-forums.net/viewtopic.php?f=33&t=49212).
* [Enhanced viewport](https://www.tt-forums.net/viewtopic.php?f=33&t=53394).  
  Extra zoomed-out zoom levels with different map display modes (page up/down or ctrl-mousewheel).  
  Selected vehicle order overlays.  
  Industry tooltips.   
  Plans (useful in multiplayer).
* Add setting for shading trees on slopes in viewports (default on).
* Add setting for alternative linkgraph overlay colour schemes.
* [When building tunnels, open new viewports at the far end of the tunnel](https://www.tt-forums.net/viewtopic.php?f=33&t=72639).
* [Smallmap screenshots](http://www.tt-forums.net/viewtopic.php?f=33&t=44596).
* Whole map screenshots at current zoom level.
* Make smallmap refresh period variable with map mode/zoom and pause state.
* Add display setting for income/cost text effects.

#### Limits

* Increase maximum number of NewGRFs to 255 in single player and multiplayer.
* [Extra large maps](http://www.tt-forums.net/viewtopic.php?f=33&t=33137).
  Maximum map size is now 256M tiles, ranging from 16k x 16k to 256 x 1M.
* Increase the limit of NewGRF house IDs in a single game from 512 to 1024.
* Increase per-vehicle order limit from 254 to 64k.
* Increase maximum setting limits for per-company vehicle-type limits.
* Increase maximum permitted vehicle, group, depot and station/waypoint name lengths.

#### Time and Date

* [Variable day length](http://www.tt-forums.net/viewtopic.php?p=1148227#p1148227).
* Add settings to show time in hours and minutes as well as or instead of days.

#### Multiplayer

* [Infrastructure sharing](http://www.tt-forums.net/viewtopic.php?f=33&t=42254)  
* Add company settings to enable competitors to buy/renew vehicles in this company's depots.  
* Add setting to control whether trains can crash with trains owned by other companies.
* [Give money to company, instead of player](https://www.tt-forums.net/viewtopic.php?f=33&t=63899), broadcast money transfer notifications to all players.
* Add setting to enable non-admin multiplayer clients to rename towns.
* Add a password mechanism to change network game settings from a network client.
* Change network protocol to send server/join and rcon passwords in hashed form instead of in clear text.
* Various changes to reduce the probability of desyncs and improve desync reporting/diagnostics.
* Add support for zstd savegame compression for autosaves and network joins.
* Increase the number of settings which can be changed in multiplayer.

#### Money

* Add setting to control dates over which inflation is applied.
* Allow shift-clicking on borrow/repay money buttons to enter a quantity.

#### Cheats

* Add support for server admin use of money, magic bulldozer, tunnels and jet crashes cheats in multiplayer.
* Add setting to allow non server admins to use the money cheat in multiplayer.
* Allow clicking the money text in the cheats window to enter a quantity.
* Add cheats to set inflation income and cost factors.
* Add cheat to set all station ratings to 100%.
* Add cheat to set all town local authority ratings to Outstanding.

#### Cargo Distribution and Link Graph

* Adjust link graph job scheduling algorithm to significantly improve responsiveness and prevent pausing.
* Improve scrolling rendering of link graph overlay on viewport and small map.
* Add new link graph distribution modes: asymmetric (equal) and asymmetric (nearest).
* Allow overriding distribution mode on a per-cargo basis, in game.
* Fix inaccurate cargo distribution and link graph overlays, and various other problems with large link graphs.

#### Input

* Add modifier key window for toggling shift/ctrl key states using mouse.
* Add IME support on Linux/SDL2 (SDL2-supported IMEs and Fcitx).

#### Console and Scripts

* Add basic tab-completion to the console window.
* Add console commands for conditional execution from game date.
* [Daily/monthly/yearly scripts](http://www.tt-forums.net/viewtopic.php?f=33&t=49595)

#### Miscellaneous

* Pause on savegame load if ctrl key is pressed.
* Ctrl-click up/down in NewGRF window to move to top or bottom.
* Add setting for when to ask for confirmation before overwriting an existing savegame file, add unique ID to savegames.
* Add more hotkeys.
* Allow AI/GS developers to reload GSs.
* Various extensions to the NewGRF developer debug tools.
* Various performance improvements.
* Various minor fixes, see changelog.
* [NewGRF specification additions](docs/newgrf-additions.html) ([online copy](https://htmlpreview.github.io/?https://github.com/JGRennison/OpenTTD-patches/blob/jgrpp/docs/newgrf-additions.html)).
* [NML specification additions](docs/newgrf-additions-nml.html) ([online copy](https://htmlpreview.github.io/?https://github.com/JGRennison/OpenTTD-patches/blob/jgrpp/docs/newgrf-additions-nml.html)).
* [AI/GS script additions](docs/script-additions.html) ([online copy](https://htmlpreview.github.io/?https://github.com/JGRennison/OpenTTD-patches/blob/jgrpp/docs/script-additions.html)).
* [Low-level code/performance changes](docs/jgrpp-low-level-changes.md).

#### Translations

* German (by Auge and Kruemelchen)  
* Korean (by kiwitreekor and TELK)  
* Japanese (by Qwerty Asd)

#### Save/load and savegame format changes  
* Various changes to improve handling of savegames which use features not in trunk.  
* Savegames from this patchpack are not loadable in trunk.  
* Savegames from trunk up to the last savegame version which has been merged into this branch (*jgrpp*) should be loadable in this patchpack.  
* Savegames from other branches which use the save/load code in the *save_ext* branch (usually suffixed: *-sx*) which are also merged into this branch (*jgrpp*), or where the added feature is marked as discardable/ignorable, should be loadable in this patchpack.  
* Savegames from other patched versions are not loadable in this patchpack except for savegames from:  
  * The *tracerestrict* branch ([routing restrictions patch](http://www.tt-forums.net/viewtopic.php?f=33&t=73397))  
  * The [Spring 2013 Patch Pack](http://www.tt-forums.net/viewtopic.php?f=33&t=66892) v2.0 - v2.4 (subject to caveats, see below)  
  * [Joker's Patch Pack](https://www.tt-forums.net/viewtopic.php?f=33&t=74365) v1.19 - v1.27 (subject to caveats, see below)  
  * [Chill's Patch Pack](https://www.tt-forums.net/viewtopic.php?f=33&t=47622) v8 and v14.7 (subject to caveats, see below)

#### Caveats for loading savegames from the [Spring 2013 Patch Pack](http://www.tt-forums.net/viewtopic.php?f=33&t=66892):  
* This is not guaranteed to be bug free  
* Savegames with huge airports are rejected  
* Map sizes greater than 16k x 16k are rejected  
* PAX signals/stations and traffic lights are cleared, leaving ordinary signals/stations/roads  
* Rail ageing/grass on tracks, trip histories, leave order/wait for cargo, auto advertising campaigns, base cost multipliers and other features not in this patch pack are dropped/ignored.  
* SpringPP v2.0.102/103 only:  
  * Savegames which have aircraft approaching, landing, taking off or landed at an oil rig are rejected  
  * The inflation cost multiplier is adjusted on load

#### Caveats for loading savegames from [Joker's Patch Pack](https://www.tt-forums.net/viewtopic.php?f=33&t=74365):  
* This is not guaranteed to be bug free  
* Logic signals are cleared, leaving ordinary signals  
* Various vehicle separation settings and partially-automatic modes are not supported.  
* Rail ageing/grass on tracks, trip histories, waiting cargo histories, station cargo punishment and other features not in this patch pack are dropped/ignored.

#### Caveats for loading savegames from [Chill's Patch Pack](https://www.tt-forums.net/viewtopic.php?f=33&t=47622):  
* This is not guaranteed to be bug free  
* Speed signals are cleared, leaving ordinary signals  
* Various vehicle, economy, town and other settings are not supported  
* Link graph data (but not settings) is cleared  
* Train stuck counters, traffic lights and other features not in this patch pack are dropped/ignored.

#### A note on branches

Many features have two branches, the *feature* branches are just the raw features, without any modified savegame code.  
There are not generally savegame compatible with anything else, except for loading of trunk savegame versions at or before the point where the branch diverged from trunk.  
All other load attempts may result in undefined behaviour.  
The *feature-sx* branches use the savegame framework in the *save_ext* branch.

* * *

* * *

# OpenTTD

## Table of contents

- 1.0) [About](#10-about)
    - 1.1) [Downloading OpenTTD](#11-downloading-openttd)
    - 1.2) [OpenTTD gameplay manual](#12-openttd-gameplay-manual)
    - 1.3) [Supported platforms](#13-supported-platforms)
    - 1.4) [Installing and running OpenTTD](#14-installing-and-running-openttd)
    - 1.5) [Add-on content / mods](#15-add-on-content--mods)
    - 1.6) [OpenTTD directories](#16-openttd-directories)
    - 1.7) [Compiling OpenTTD](#17-compiling-openttd)
- 2.0) [Contact and community](#20-contact-and-community)
    - 2.1) [Contributing to OpenTTD](#21-contributing-to-openttd)
    - 2.2) [Reporting bugs](#22-reporting-bugs)
    - 2.3) [Translating](#23-translating)
- 3.0) [Licensing](#30-licensing)
- 4.0) [Credits](#40-credits)

## 1.0) About

OpenTTD is a transport simulation game based upon the popular game Transport Tycoon Deluxe, written by Chris Sawyer.
It attempts to mimic the original game as closely as possible while extending it with new features.

OpenTTD is licensed under the GNU General Public License version 2.0, but includes some 3rd party software under different licenses.
See the section ["Licensing"](#30-licensing) below for details.

## 1.1) Downloading OpenTTD

OpenTTD can be downloaded from the [official OpenTTD website](https://www.openttd.org/).

Both 'stable' and 'nightly' versions are available for download:

- most people should choose the 'stable' version, as this has been more extensively tested
- the 'nightly' version includes the latest changes and features, but may sometimes be less reliable

On some platforms OpenTTD will also be available via your OS package manager or a similar service.


## 1.2) OpenTTD gameplay manual

OpenTTD has a [community-maintained wiki](https://wiki.openttd.org/), including a gameplay manual and tips.


## 1.3) Supported platforms

OpenTTD has been ported to several platforms and operating systems.

The currently supported platforms are:

- Linux (SDL (OpenGL and non-OpenGL))
- macOS (universal) (Cocoa)
- Windows (Win32 GDI / OpenGL)

Other platforms may also work (in particular various BSD systems), but we don't actively test or maintain these.

### 1.3.1) Legacy support
Platforms, languages and compilers change.
We'll keep support going on old platforms as long as someone is interested in supporting them, except where it means the project can't move forward to keep up with language and compiler features.

We guarantee that every revision of OpenTTD will be able to load savegames from every older revision (excepting where the savegame is corrupt).
Please report a bug if you find a save that doesn't load.

## 1.4) Installing and running OpenTTD

OpenTTD is usually straightforward to install, but for more help the wiki [includes an installation guide](https://wiki.openttd.org/en/Manual/Installation).

OpenTTD needs some additional graphics and sound files to run.

For some platforms these will be downloaded during the installation process if required.

For some platforms, you will need to refer to [the installation guide](https://wiki.openttd.org/en/Manual/Installation).


### 1.4.1) Free graphics and sound files

The free data files, split into OpenGFX for graphics, OpenSFX for sounds and
OpenMSX for music can be found at:

- https://www.openttd.org/downloads/opengfx-releases/ for OpenGFX
- https://www.openttd.org/downloads/opensfx-releases/ for OpenSFX
- https://www.openttd.org/downloads/openmsx-releases/ for OpenMSX

Please follow the readme of these packages about the installation procedure.
The Windows installer can optionally download and install these packages.


### 1.4.2) Original Transport Tycoon Deluxe graphics and sound files

If you want to play with the original Transport Tycoon Deluxe data files you have to copy the data files from the CD-ROM into the baseset/ directory.
It does not matter whether you copy them from the DOS or Windows version of Transport Tycoon Deluxe.
The Windows install can optionally copy these files.

You need to copy the following files:
- sample.cat
- trg1r.grf or TRG1.GRF
- trgcr.grf or TRGC.GRF
- trghr.grf or TRGH.GRF
- trgir.grf or TRGI.GRF
- trgtr.grf or TRGT.GRF


### 1.4.3) Original Transport Tycoon Deluxe music

If you want the Transport Tycoon Deluxe music, copy the appropriate files from the original game into the baseset folder.
- TTD for Windows: All files in the gm/ folder (gm_tt00.gm up to gm_tt21.gm)
- TTD for DOS: The GM.CAT file
- Transport Tycoon Original: The GM.CAT file, but rename it to GM-TTO.CAT


## 1.5) Add-on content / mods

OpenTTD features multiple types of add-on content, which modify gameplay in different ways.

Most types of add-on content can be downloaded within OpenTTD via the 'Check Online Content' button in the main menu.

Add-on content can also be installed manually, but that's more complicated; the [OpenTTD wiki](https://wiki.openttd.org/) may offer help with that, or the [OpenTTD directory structure guide](./docs/directory_structure.md).

### 1.5.1) AI opponents

OpenTTD comes without AI opponents, so if you want to play with AIs you have to download them.

The easiest way is via the 'Check Online Content' button in the main menu.

You can select some AIs that you think are compatible with your playing style.

AI help and discussions may also be found in the [AI section of the forum](https://www.tt-forums.net/viewforum.php?f=65).

### 1.5.2) Scenarios and height maps

Scenarios and heightmaps can be added via the 'Check Online Content' button in the main menu.

### 1.5.3) NewGRFs

A wide range of add-content is available as NewGRFs, including vehicles, industries, stations, landscape objects, town names and more.

NewGRFs can be added via the 'Check Online Content' button in the main menu.

See also the wiki [guide to NewGRFs](https://wiki.openttd.org/en/Manual/NewGRF) and [the forum graphics development section](https://www.tt-forums.net/viewforum.php?f=66).

### 1.5.4) Game scripts

Game scripts can provide additional challenges or changes to the standard OpenTTD gameplay, for example setting transport goals, or changing town growth behaviour.

Game scripts can be added via the 'Check Online Content' button in the main menu.

See also the wiki [guide to game scripts](https://wiki.openttd.org/en/Manual/Game%20script) and [the forum graphics game script section](https://www.tt-forums.net/viewforum.php?f=65).

### 1.6) OpenTTD directories

OpenTTD uses its own directory structure to store game data, add-on content etc.

For more information, see the [directory structure guide](./docs/directory_structure.md).

### 1.7) Compiling OpenTTD

If you want to compile OpenTTD from source, instructions can be found in [COMPILING.md](./COMPILING.md).


## 2.0) Contact and Community

'Official' channels

- [OpenTTD website](https://www.openttd.org)
- IRC chat using #openttd on irc.oftc.net [more info about our irc channel](https://wiki.openttd.org/en/Development/IRC%20channel)
- [OpenTTD on Github](https://github.com/openTTD/) for code repositories and for reporting issues
- [forum.openttd.org](https://forum.openttd.org/) - the primary community forum site for discussing OpenTTD and related games
- [OpenTTD wiki](https://wiki.openttd.org/) community-maintained wiki, including topics like gameplay guide, detailed explanation of some game mechanics, how to use add-on content (mods) and much more

'Unofficial' channels

- the OpenTTD wiki has a [page listing OpenTTD communities](https://wiki.openttd.org/en/Community/Community) including some in languages other than English


### 2.1) Contributing to OpenTTD

We welcome contributors to OpenTTD.  More information for contributors can be found in [CONTRIBUTING.md](./CONTRIBUTING.md)


### 2.2) Reporting bugs

Good bug reports are very helpful.  We have a [guide to reporting bugs](./CONTRIBUTING.md#bug-reports) to help with this.

Desyncs in multiplayer are complex to debug and report (some software development skils are required).
Instructions can be found in [debugging and reporting desyncs](./docs/debugging_desyncs.md).


### 2.3) Translating

OpenTTD is translated into many languages.  Translations are added and updated via the [online translation tool](https://translator.openttd.org).


## 3.0) Licensing

OpenTTD is licensed under the GNU General Public License version 2.0.
For the complete license text, see the file '[COPYING.md](./COPYING.md)'.
This license applies to all files in this distribution, except as noted below.

The squirrel implementation in `src/3rdparty/squirrel` is licensed under the Zlib license.
See `src/3rdparty/squirrel/COPYRIGHT` for the complete license text.

The md5 implementation in `src/3rdparty/md5` is licensed under the Zlib license.
See the comments in the source files in `src/3rdparty/md5` for the complete license text.

The implementations of Posix `getaddrinfo` and `getnameinfo` for OS/2 in `src/3rdparty/os2` are distributed partly under the GNU Lesser General Public License 2.1, and partly under the (3-clause) BSD license.
The exact licensing terms can be found in `src/3rdparty/os2/getaddrinfo.c` resp. `src/3rdparty/os2/getnameinfo.c`.

The implementation of C++17 `std::optional` in `src/3rdparty/optional` is licensed under the Boost Software License - Version 1.0.
See `src/3rdparty/optional/LICENSE_1_0.txt` for the complete license text.


## 4.0 Credits

See [CREDITS.md](./CREDITS.md)
