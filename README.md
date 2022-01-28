# solar-position-calculator
A program for calculating solar position from the website https://www.esrl.noaa.gov/gmd/grad/solcalc/. This program calculates the **Azimuth** and **Elevation** values based on time and location information. 

## Time zone format
The solar position calculation uses the [Coordinated Universal Time or UTC](https://en.wikipedia.org/wiki/Coordinated_Universal_Time) time standard, and only requires the offset not the 'UTC'.

## Time format
This program uses the [ISO 8601](https://en.wikipedia.org/wiki/ISO_8601) time format, where hour (hh) is represented between [00-23], minute (mm) with [0-60], and seconds (ss) with [0-60]. For instance, if you want to represent a time 3:25:42 PM with ISO 8601 format it shall be 15:25:42 with no AM/PM extenstion.

## How to run the solar position calculator
To calculate the **Azimuth** and **Elevation** values, the program requires 7 arguments respectively: 
  * Year
  * Month
  * Day
  * Longtitude
  * Latitude
  * Offset of time zone
  * Time (hh:mm:ss)

For example if you want to calculate the **Azimuth** and **Elevation** values in **2021 February 15**, at **11:37:52** (hh:mm:ss) at America/Chicago (approximately **Longititude: -98.583**, **Latitude: 39.833**, **UTC: -6:00**). Your initial arguments should be:

`./solar-position-calculator -y 2021 -m 2 -d 15 -o -98.583 -a 39.833 -u -6:00 -t 11:37:52`

To see view the help menu, run:

`./solar-position-calculator --help`

## Citing
If you have used our work please cite us
```tex
@InProceedings{Ufuktepe_2021_ICCV,
    author    = {Ufuktepe, Deniz Kavzak and Collins, Jaired and Ufuktepe, Ekincan and Fraser, Joshua and Krock, Timothy and Palaniappan, Kannappan},
    title     = {Learning-Based Shadow Detection in Aerial Imagery Using Automatic Training Supervision From 3D Point Clouds},
    booktitle = {Proceedings of the IEEE/CVF International Conference on Computer Vision Workshops (ICCVW), Workshop on Analysis of Aerial Motion Imagery (WAAMI)},
    year      = {2021}
}
```
