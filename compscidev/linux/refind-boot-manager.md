---
description: Boot managers for people who use a mac. Last updated 22 Dec 2021.
---

# rEFInd Boot Manager

## Purpose

If you are a computer science student who bought a mac thinking that you wouldn't need to really use linux because Mac OS runs unix and found out you were wrong? This article is for you.

#### This article:

1. Explain how bootcamp limits you to only installing Windows.&#x20;
2. Provides an order of when to install your OS, rEFInd, and how to install your OS in a way that doesn't include GRUB.
3. Provides resources

## What You'll Need

* [Etcher](https://etcher.download/): `/Collections/Applications/Operating Systems/ISO Burners for Mac and Windows`
* Latest version of Ubuntu/Elementary iso.

## Setup Order Overview

Here is the order of things:

1. First, we'll use [_Etcher_](https://etcher.download/) or [_Rufus_](https://rufus.ie/en/) or your favorite ISO burner to make a bootable flash drive (or CDs if you want to be cool).
2. Install your operating system, but tell the installer to install _without_ installing the GRUB bootloader using something called "[EFI stub loading](https://wiki.debian.org/EFIStub)". This is going to allow us to launch the linux kernel directly without an intermediary boot-loader like GRUB. (Though, we're going to make rEFInd to be our intermediary between MacOS and Linux/Windows.
   1. **Elementary OS:** boot into the "try me" section. Launch installer with `$ ubiquity -b` , where the `-b` flag runs it without installing the GRUB boot loader. Choose the fee space and format it as **Ext4** and set its mount point to `/`. Choose and apply to finish installing elementary OS.
3. You might be able to use Mac OS's "hold the option key and hope" method of booting into things; however, the article I'm reading suggests that I use rEFInd, so I'm going to do that.

## Installing rEFInd

Just go to the first thing on the works cited list below and start reading from **Install rEFInd Boot Manager**. This works - at least for Elementary OS, but I don't see why the boot manager won't also find other bootable operating systems.

## Works Cited

I used these to help me make this guide:

{% embed url="http://aroman.github.io/elementary-on-a-mac" %}

{% embed url="https://wiki.debian.org/EFIStub" %}
