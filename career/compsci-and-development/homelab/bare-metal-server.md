# Bare Metal Servers

## Core Tools

* [ProxMox](https://proxmox.com/en/)

## 2U Specs For Purchase?

Noah bought servers after covid started. Trapped at home and bored.

* Pair of 8-core 16 thread Xeons from intel core 3rd gen.
  * Single core performance isn't great
  * Idle power consumption isn't great.
* Has PCIe. No M.2 specs.
  * Get solid state drives that slot into where the hard drives are.
  * Held back by the total speed of the RAID card & storage controller.
  * SASS SSDs. (Not SCSI ssds). Lot of 24 1TBs are cheap.
* Doesn't have SATA, but SCUZI.
* Has a 2003 Civic SI too?
* OpenMediaVault

<figure><img src="../../../.gitbook/assets/CleanShot 2024-07-05 at 16.39.51@2x.png" alt=""><figcaption></figcaption></figure>

<figure><img src="../../../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt=""><figcaption></figcaption></figure>

* [https://support.hpe.com/hpesc/public/docDisplay?docId=emr\_na-c03235277](https://support.hpe.com/hpesc/public/docDisplay?docId=emr_na-c03235277)
* [https://www.hpe.com/psnow/doc/c04123238](https://www.hpe.com/psnow/doc/c04123238)
* 2 CPUs. 64GB of RAM, supports 128GB with the same sticks. $25 for 32gbs.
* Actual AI acceleration. Be aware of that NVIDIA handicaps their
  * RTX graphics cards for machine learning instead of GTX
  * Handicaps that compared to the Quatros.
  * All TSLA's data cards have some different instruction sets. Double precision floating point operations and 64-bit flops.
  * FP64 calculations are leveraged by many ML algos. 3090 vs A6000 and despite them having the same GPU core, the quadro had over 2x the performance on FP64 calculations.
  * Software limitation.
  * They are effective at it. Have 24gb of VRAM. Huge for ML stuff.
  * Dig into what you're looking for into acceleration & how do they use their hardware. If they use FP64, you could be better served with things that aren't consumer hardware.
* If they don't need a lot of horsepower, but need a lot of memory, you can find older datacenter tesla cards (NVIDIA Tesla K80), but the core on it is pretty slow. All fanless & meant to go and 3D print a fan shroud that'll push air into it.
  * Tesla M80
  * Double memory & didn't gimp it with drivers costs wayyyy more.
  * Quadro cards are not restricted in certain operations you can perform on them.
