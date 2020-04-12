# Data-Structures---Bus-Route-Linked-List
https://acm.cs.nthu.edu.tw/problem/12222/
## Description

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

## Input
The first number is the number of the following operations.  Each of the following line contains an operation.

Two additional rules:

* The bus route contains NTHU and TSMC in the beginning.
* NTHU is never deleted

## Output

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
