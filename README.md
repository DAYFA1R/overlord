# Overlord
**Context switching between projects made simple**

*by DAYFA1R*

## Description
Building this out because I want to streamline context switching on different projects, and standardize the tech-specific commands I run into generically-termed commands that can be configured on a per-project basis (eg. set up the commands once and never worry about it again). For example, running a compiled project and building the project from source is a pretty common ritual among a variety of languages/frameworks. If you are maintaining a Node.js app, maybe you use `npm run start` to boot up your app. On the other hand, maybe you are mainting a C++ application and are manually running the output file as `./yourApplication.out`. Essentially, the purpose of this software is to define these commands *once* in a configuration file, and simply execute `overlord run`.

Another objective of this program is to remove the redundancy of having to traverse your file system. If you are on a system where you have multiple projects relating to multiple organizations, some of which are for sandbox/demo purposes and others which are full fledged applications, you probably have some sort of semantic folder structure to keep things separate. That's cool and all, but as of late I've become conscious of how much `cd`ing and tab completion I'm doing to jump around my system throughout my day to day. I'd essentially like to have a representation of the `cd` command within `overlord`, which will take you directly to your project (eg. `overlord <myProjectId>` == `cd ~/some/folder/with/my/repo`).

Two things I'd like to call out before what I can only anticipate as probable criticism:

*	Yes, you can define a series of variables or aliases in your profile to store everything this application does, and just shorthand all this stuff using them. But why *not* leave your shell settings clean and just have a decently baked application to handle it all instead?

*	While this may simplify things for newer developers, I by no means would suggest using this program as a replacement for **actually learning/getting into the habit of using UNIX commands**, or the native tools your framework or library ships with. This is intended to *at best* give back a few seconds here and there to people who have already mastered the commands this program intends to streamline.

## Features/Usage/Roadmap
Subject to change, but this section essentially represents the spec that I wish to build `overlord` in mind with.

### `overlord` (`ov`): Get general usage information
Nothing special to see here, it's essentially the same as running `git`, or the `help` argument in most applications. 

### `overlord init` (`ov i`): Initialize new project
Initializes the current directory as a new overlord project. Will run the init helper if a `.overlord.yaml` file is not already present in the directory.

#### Additional arguments
*	`-r`: Reruns the init helper prepopulated by `.overlord.yaml`

### `overlord <unique-id>` (`ov <uid>`): Jump to project directory
Essentially `cd`'s you into the root directory of your project (determined by the unique id) that was specified through init.

### `overlord build` (`ov b`): Build project
Executes whatever was provided as the build command during the init process. Can also be supplied in the format `overlord <unique-id> build` if you want to build a project external to your current directory, without actually changing directories.

#### Additional arguments
*	`-r`: Runs the project after build process is completed

### `overlord run` (`ov r`): Run project
Executes whatever was provided as the run command during the init process. Can also be supplied in the format `overlord <unique-id> run` if you want to run a project external to your current directory, without actually changing directories.

### `overlord edit` (`ov e`): Edit project/open in editor
Executes whatever was provided as the editor command during the init process.

## Footnotes
*	Yes, the name of this project is 100% inspired by Starcraft.