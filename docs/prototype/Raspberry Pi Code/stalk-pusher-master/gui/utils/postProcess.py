'''
based on Wen's matlab code:

Witold,

Sure, my code only tries to neglect the wrong maxload (like hitting other plants) and find the true maxload and it's index. If the true maxload's index (a) disagree with the index (b) of the max load value, then b is the index of the anomalies.
The idea is a true maxload can't be too far away from its left and right neighbors, so the code will first rank the raw load values, and starting from the maximum, compare its value with the avg of the left two (if any) and the avg of the right two (if any). If either of the distance is smaller than a threshold (dis_pass), then it's a true maxload. Otherwise the code will check the next highest load value.

Here's the code:

loads = loads / 120;
dis_pass = 1; 
loads = loads';
        [loads_sort,index] = sort(loads,'descend');

        for i = 1 : max(index)
            
            max_load = loads_sort(i);
            maxdex = index(i); 
            [r,c] = size(loads);
            
              % *********************NEW CODE *******************
            if maxdex == 1 || maxdex == 2
                disp(['test ' num2str(test_num) 'maximum raw load at the first two datap points, error code changed to 2']);
                errorCode = errorCode*10+2;
                break;
            end
             % ****************** END NEW CODE *******************
            
            
            
            left = loads(1,maxdex-2:maxdex-1);
            left_val = mean(left);
            
            if maxdex ==c
                right = max_load;
            elseif maxdex == c-1
                right = loads(1,maxdex+1);
            else
                right = loads(1,maxdex+1:maxdex+2);
            end
            right_val = mean(right);
            if ((max_load - left_val) <=dis_pass) || ((max_load - right_val) <=dis_pass)
                break;
            end
            
        end
        if (max_load < min_max_load)
            fprintf('%s, #%d: max load of %fN below threshold of %f, error code changed to 1.\n', test_plot, test_num, ml, min_max_load);
            errorCode = errorCode*10+1;
        end
'''
import numpy as np
dis_pass = 1
dis_pass_p = 0.1


def checkValidity(loads):
    truemax = 0
    truemaxind = -1
    
    bad_ind=[]
    if type(loads)==type(1) or len(loads) ==0:
        return (truemaxind, bad_ind)
    loads_sort = -np.sort(-loads)
    index = np.argsort(-loads)
    
    for i in range(max(index)):
        max_load = loads_sort[i]
        maxdex = index[i]
                
        c = np.size(loads)        
        
        if maxdex == 0:
            left = max_load
        elif maxdex == 1:
            left = loads[0]
        else:
            left = loads[maxdex-2:maxdex]
        
        if maxdex == c-1:
            right = max_load
        elif maxdex == c-2:
            right = loads[-1]
        else:
            right = loads[maxdex+1:maxdex+3]

        left_val = np.mean(left)            
        right_val = np.mean(right)
#         print('#############')
#         print('maxdex', max_load, 'dis_pass_p', max_load *dis_pass_p)
#         print('left', left, left_val, abs(max_load - left_val))
#         print('right', right, right_val, abs(max_load - right_val))

        if (abs(max_load - right_val) <= abs(max_load *dis_pass_p) or abs(max_load - left_val) <= abs(max_load *dis_pass_p)):
#             print('good')           
            if abs(max_load) > abs(truemax):
                truemax = max_load
                truemaxind = maxdex
        else:
            bad_ind.append(maxdex)
#             print('bad')

    return (truemaxind, np.array(bad_ind))
# def checkValidity(loads):
#     truemax = 0
#     truemaxind = -1
#     dis_pass = 1/max(loads)
#     bad_ind=[]
#     loads_sort = -np.sort(-loads)
#     index = np.argsort(-loads)
#     for i in range(max(index)):
#         max_load = loads_sort[i]
#         maxdex = index[i]
#         
#         if maxdex == 0 or maxdex == 1:
#             bad_ind.append(maxdex)
#             continue
#         
#         c = np.size(loads)
#         
#         left = loads[maxdex-2:maxdex];
#         left_val = np.mean(left);
#         
#         if maxdex == c-1:
#             right = max_load;
#         elif maxdex == c-2:
#             right = loads[-1];
#         else:
#             right = loads[maxdex:maxdex+2]
#             
#         right_val = np.mean(right)
#         
#         if (abs((max_load - left_val)) <=dis_pass) or (abs((max_load - right_val)) <=dis_pass):
#             print('good', (max_load - left_val), (max_load - right_val))
#             if abs(max_load) > abs(truemax):
#                 truemax = max_load
#                 truemaxind = maxdex
#         else:
#             bad_ind.append(maxdex)
#             print('bad', (max_load - left_val), (max_load - right_val))
# 
#     return (truemaxind, np.array(bad_ind))
    
