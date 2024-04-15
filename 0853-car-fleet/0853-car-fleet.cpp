class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //sorting the position array according to which i will sort the speed array which will help us in bringing the cars near of its adjacent cars in the lane
        //and ultimately this will help me in :- while i will be comparing the speeds of adjacent cars to check wheather they will form fleet or not using stack
        
        //as i have to arrange elements of speed array according to sorted position array :- means if a car has position of 2 and speed of 6
        //and i sort the position array due to which the position value 2 placed at 0th index of position array then its corresponding speed i.e 6 should must be placed in 0th index of speed array

        ///for this reason i will store corresponding speed of cars with their position in a map and after i sort the position array i will arrange the speed array according to that using the map
        unordered_map <int,int> car;
        int n=position.size();
        for(int i=0;i<n;i++){
            car[position[i]]=speed[i];
        }
        //sorting the position array
        sort(position.begin(),position.end());
        //aranging speed array according to sorted positionn array
        for(int i=0;i<n;i++){
            speed[i]=car[position[i]];
        }

        //now our work is to calculate time required for each car to reach target
        vector<float> time(n);
        for(int i=0;i<n;i++){
             // time=distance/speed .....(distance=target-current position)
            time[i]=(target-position[i])/((float)speed[i]);//explicit type casting for forming ans in float
            //here we will find time in floaating point :- imagine target=10,pos=6,speed=3 here if we will not use ciel the time will be 1 unit but time should be 1.33  unit to reach the target
          
        }

        /*.....now using stack we will check wheather adjacent car will form fleet :- if any car takes more or equal time to reach the target that its previous car then thay will form fleet as its previous car will colide with it they will drive bumper to bumper till target
        i am considering equal time beacuse when car have diff position(obviously all car will have dif position due to one lane) but require same time to reach target menas they will meet each other at perticularly target which is also form a fleet
        what will i do:--- i will imagine stack as a lane.initialy there will be no car in the stack so i will push time of 1st car into stack and i will move to next car(using loop over the time array)
        then i will check does my current car takes more or equal time than the time present at top of stack(time of its previous car) if yes then i will pop the element at top of stack and push the current time
        why i am poping??? imagine if a car will take 5 unit time to reach  target and its front car will take 9 unit timme to do that then obviously they will colide in way and reach target in 9 unit time means now they are merged with each other
        so by poping previous time and pushing the current time i am depicting that previous car merged and formed a fleet with current car

        if next car take less time as compared to previous car i.e current element in time array is smaller than the element at top of stack the i will dont pop anything and directly push current element
        depicting previous and current car will never meet and they will be part of different fleet
        here NOTICE ONE THING IN THIS WAY AT LAST OF ALL OPERATION THE SIZE OF STACK WILL BE SAME AS THE NUMBER OF FLEET .....*/

        stack<float> fleetCount;
        for(int i=0;i<time.size();i++){
            while( !fleetCount.empty() && time[i]>=fleetCount.top() ){
                fleetCount.pop();
            }

            fleetCount.push(time[i]);
            /* how intuitive it is to think that every element(or car) will get pushed into stack for sure but before that inside the while loop
            we are just checking will any of it's previous car take less time(means fatser than current car) to reach target if yes then we are poping them
            which typically represent merging them with current car (or those car will drive bumper to bumper with current car and will considered as one) */
        }

        return fleetCount.size(); //THE SIZE OF STACK WILL BE SAME AS THE NUMBER OF FLEET
    }
};

/*APPROACH OR INTUITION:- CALCULATING TIME WAS THE ABSOLUTE STEP TO DO AND AFTER THAT I IMAGINED A CASE WHERE AMMONG SOME OF CARS IN LANE IF ANY CAR TAKES MORE TIME TO REACH THE TARGET 
THAN ITS PREVIOUS CARS THEN ONE BY ONE ITS  PREVIOUS CARS WILL COLIDE WITH IT AND IF I USE ITRATIVE APPROACH THEN TO CHECK HOW MANY NUMBER OF CARS WILL COLIDE WITH CURRENT CAR (I NEED TO COUNT AS DOING THAT ONLY I CAN FIND OUT THE NO OG FLEETS)
I HAVE TO BREAK THE CURRENT FORWARD TRAVERSING AND WE HAVE TO TRAVERSE THE ARRAY IN BACKWARD DIRECTION */ 
/*AND I KNOW THAT WHEN EVER I NEED TO TRAVERSE ANYTHING BACKWORDS THERE I MUST THINK ABOUT STACK AS STACK HELPS US TO STORE THOSE ELEMENTS AND ACCES THEM EASILY AS COMPARED TO ITRATIVE APPROACH AS STACK ALLOWS US TO CONTINUE THE CURRENT TRAVERSING AND STILL ALLOWS US TO SEE BACK ELEMENTS */