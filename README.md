This is the README for <[***Symphony of Pew Pew***]>, a simple game developed by
<[***TDB Games***®]> for the LULZ.

Internal
========

I – <drachlyznardh@roundhousecode.com> – am personally working on this
repository in order to maintain its history as clean as possible. To do that, I
spend time every night invoking the Machine Spirit.

> Although the final layout will change eventually, right now this (remote)
repository is populated with a number of branches with a hierarchical structure.

The layout did change. We have a **branching model** on three levels.

> The [master] branch will move by fast-forward only based on [devel]. The [devel]
branch will be updated by [git merge --no-ff] on specific chunchs of history of
one of the topic branches. Topic branches can be updated by member users in any
way the like.

Actually, the current model structure is this:

- *master* is the branch for official releases;
- *devel* is the branch for all the stable features;
- *ftr-&lt;name&gt;* branches are used to submit features;

Here's a list of **PLEASE do** and **PLEASE do not**:

- PLEASE, add & commit only useful content. Remove from each commit object
  files, swap files, logs and every other non-essential content.
- PLEASE, keep the history clean. I can fix it but I will suffer.
- PLEASE, remember to pull (fetch & merge) from each remote branch above the one
  you are working on BEFORE pushing.
- PLEASE, when you push, do it on a TOPIC branch. DO NOT push devel or master.
- PLEASE, do not push for backup. When you push, do it to share useful &
  functional content you believe ready to be released.
- PLEASE, when you push to share, since I have to merge it, PLEASE be sure to
  share useful & substantial content.

Do not fear. Everything in this section is written on the sand, it can be
changed and I am here to answer many of your questions.

About FEATURE branches
----------------------

> As I – <drachlyznardh@roundhousecode.com> – already mentioned in the GIT guide,
topic branches are long-running branches that focus on a specific task.

Actually, that guide was completely rewritten. There **will not** be any other
long-running branches other than *master* and *devel*; each *feature* branch
shall be push, evaluated and then either accepted in *devel* or discarded.

> Use the following section on list and describe the topic branch you introduce.

Still, if you really need to say something about your *feature*, please do it
here on this list.

List of FEATURE branches
------------------------

The *buildsystem* branch is dedicated to CMake & CMake stuff. Its development
will focus on CMakeLists.txt files, CMake tuning and related issues.

