# PixelCon

Repository for the Practical 3 files.

## Team Members

- Kyle Pillay
- Takunda Mugwagwa
- Brett Pitts

## Event Concept

PixelCon is a gaming convention coordinated by EventFlow. The venue is
made up of a root event containing three halls; PC Hall, Console Hall, and
Outdoor Plaza, with PC Hall further containing a nested Tournament Zone.
Each hall contains individually reactive operational units (gaming stations,
booths, desks, vendors) that respond differently to the same event-wide
notices (schedule changes, capacity alerts, weather alerts, evacuation, etc.)
depending on their own type and state.

## Building

```bash
make all
./eventflow
```

Requires a C++11-compatible compiler.

## Generating Documentation

```bash
doxygen Doxyfile
```

Open `docs/html/index.html` in a browser.

## Architecture Overview

EventFlow combines Composite and Observer. EventComponent is the shared interface for EventUnit (Leaf) and EventGroup (Composite), letting a client treat a single station or an entire hall the same way. EventGroup also acts as both Subject and Observer, so notices issued by EventControl cascade down through nested groups to whichever concrete units are registered to receive them.

## Project Structure

Follow the structure below when adding files to the repository:

```text
Practical_3/
├── include/
│   ├── EventComponent.h
│   ├── Observer.h
│   └── ...
│
├── src/
│   ├── EventComponent.cpp
│   ├── Observer.cpp
│   └── ...
│
├── main.cpp
├── Makefile
└── Anything else
```

## Branching Strategy

Use feature branches for individual pieces of functionality. Merge completed work into main.

```text
main
├── feature/event-component
├── feature/observer-subject
└── feature/leaves-batch1
```