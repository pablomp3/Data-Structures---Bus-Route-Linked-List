# Data-Structures---Bus-Route-Linked-List

* Content:
  1. **Bus Route Linked List v2:** https://acm.cs.nthu.edu.tw/problem/12222/
  1. **Bus Route Distance Linked List:** https://acm.cs.nthu.edu.tw/problem/12226/

# Bus Route Linked List v2
### Description

![](https://github.com/pablomp3/Data-Structures---Bus-Route-Linked-List/blob/master/Bus_Route_Linked_List.png)

A bus route editor needs to support two operations:

**INSERT (src, dst, new, method)**

* src: the name of the source bus stop
* dst: the name of the destination bus stop, which is next to the src stop
* new: the name of the newly added bus stop
* method:
  * 1: insert the new stop in between src-->dst
  * 2: In addition to src-->dst, also insert the same stop in between dst-->src if appropriate
  
**DELETE (name)**

* Delete the named bus stop

NOTE: The same station should not occur consecutively, that is, NTHU=>HSCS=>HSCS=>NCTU is not okay, and it should be changed to: NTHU=>HSCS=>NCTU

HINT: Use Linked Lists.

### Input
The first number is the number of the following operations.  Each of the following line contains an operation.

Two additional rules:

* The bus route contains NTHU and TSMC in the beginning.
* NTHU is never deleted

### Output

Traverse the final bus route from NTHU and back to NTHU.
![](https://github.com/pablomp3/Data-Structures---Bus-Route-Linked-List/blob/master/output%20instructions.png)



### Sample Input  

    10
    INSERT NTHU TSMC APPLE 2
    INSERT APPLE NTHU Mackay 1
    INSERT APPLE Mackay KFSH 1
    INSERT Mackay NTHU ITRI 2
    DELETE ITRI
    INSERT TSMC APPLE ITRI 2
    DELETE APPLE
    INSERT ITRI TSMC HCHS 1
    INSERT TSMC ITRI MTK 2
    DELETE TSMC

### Sample Output

    NTHU->ITRI->HCHS->MTK->ITRI->KFSH->Mackay->NTHU

#---------------------------------------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------------------------------------

# Bus Route Distance Linked List

### Description
Given a series of bus route insertions, build a bus route. Given a series of distance queries, calculate the number of stops in between the source and destination (**not the number of unique nodes in the linked lists, you will have to consider 2 directions to calculate distance**).

The bus route contains NTHU and TSMC in the beginning.

The operations you must implement are listed below:

INSERT (src, dst, new, method)
src: the name of the source bus stop
dst: the name of the destination bus stop, which is next to the src stop
new: the name of the newly added bus stop
method:
1. Insert the new stop in between srcdst
1. In addition to srcdst, also insert the same stop in between dstsrc if appropriate

RENAME (old_name, new_name)
Replace the stop with the old_name with the new_name

TOTAL ()
Output the total number of stops starting from NTHU and back to NTHU (NTHU is only counted once)

DISTANCE (src, dst)
Output the minimum number of stops from src to dst
If src or dst does not exist, output “Missing src”, “Missing dst”, or “Missing both”

**No deletion or reversion operations**.

Example route from input:

![](https://github.com/pablomp3/Data-Structures---Bus-Route-Linked-List/blob/master/distance_1.png)

### Input

* An integer n, representing number of operations, followed by newline.
* N lines, representing the operations. Each line will look like below:
  * 'RENAME', 'old name', 'new name', separated by a whitespace, with new line at the end, OR.
  * 'INSERT', 'source name', 'destination name', 'new station to insert' separated by a whitespace, with new line at the end.
* An integer m, represeting the number of distances you should output, followed by newline.
* M lines, the distances to calculate. Each line will look:
  * 'source name' and 'destination name', separated by a whitespace, with new line at the end.

![](https://github.com/pablomp3/Data-Structures---Bus-Route-Linked-List/blob/master/distance_2.png)

### Output

* The word 'total', followed by the number of stops in the bus route (traversing starting from NTHU and ending back in NTHU, **not the number of unique nodes in the linked lists you will have to consider 2 directions to calculate distance**), separated by whitespace and followed by a new line.
* m lines representing the distances, each line will look like below:
  * If both stations exist: 'source name', 'destination name', number of stops in between, separated by whitespace and followed by a new line.
  * If source station src doesn't exist: 'source name', 'destination name', and  'Missing src', separated by whitespace and followed by a new line .
  * If destination doesn't exist: 'source name', 'destination name', and  'Missing dst', separated by whitespace and followed by a new line .
  * If neither destination nor source exist: 'source name', 'destination name', and  'Missing both', separated by whitespace and followed by a new line. 

![](https://github.com/pablomp3/Data-Structures---Bus-Route-Linked-List/blob/master/distance_3.png)

### Sample Input  

    20
    INSERT NTHU TSMC PCAR 2
    INSERT PCAR TSMC ATVI 2
    RENAME PCAR WYNN
    INSERT WYNN ATVI AMZN 2
    INSERT AMZN ATVI SWKS 2
    INSERT TSMC ATVI AMAT 1
    INSERT WYNN AMZN SIRI 1
    INSERT AMZN SWKS WLTW 2
    INSERT ATVI TSMC BMRN 2
    INSERT SIRI AMZN CSX 2
    INSERT AMAT ATVI FOXA 2
    RENAME SWKS HSIC
    RENAME WLTW TMUS
    INSERT WYNN SIRI CTRP 2
    RENAME HSIC CTSH
    RENAME ATVI NTAP
    INSERT TMUS CTSH NXPI 2
    INSERT NTAP CTSH NTES 2
    INSERT FOXA NTAP QCOM 2
    INSERT BMRN TSMC MXIM 1
    11
    NTHU TSMC
    TSMC NTHU
    NTHU NTHU
    NTES NTES
    AMZN WYNN
    WYNN AMZN
    CTRP WYNN
    WYNN CTRP
    ATVI AMAT
    AMAT SWKS
    WLTW PCAR
    

Sample Output

    Total 24
    NTHU TSMC 13
    TSMC NTHU 11
    NTHU NTHU 0
    NTES NTES 0
    AMZN WYNN 1
    WYNN AMZN 4
    CTRP WYNN 21
    WYNN CTRP 1
    ATVI AMAT Missing src
    AMAT SWKS Missing dst
    WLTW PCAR Missing both
    
