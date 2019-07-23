class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	/* Using the topological sorting algorithm */

    	// who knows if the size of prerequisites, or numCourses ???
    	if ( prerequisites.empty() || numCourses == 0) return true;

    	// use unordered_multimap to mimic a graph
    	std::unordered_multimap<int, int> graph; // key is prerequisite
    	vector<int> count_indegree(numCourses, 0);

        // count the in_degree first
        for (auto course_pair : prerequisites) {
        	// course_pair.second is the prerequesite
        	count_indegree[course_pair.first]++;
        	graph.insert( std::make_pair(course_pair.second, course_pair.first) );
        }

        // construct a queue with the key as the course number
        std::queue<int> q; 

        // put courses with in_degree 0 into the q as starter nodes
        for (int i = 0; i < numCourses; i++) {
        	if (count_indegree[i] == 0) q.push(i);
        }

        if ( q.empty() ) return false; // no in_degree equaling 0 node

        // construct an empty topological sorted vector.
        // if there exist a topological vector in the end: 
        // the course schedule can be done properly
        std::vector<int> topological_sorted_vec;
        while ( !q.empty() ) {
        	int cur_course_num = q.front();
        	topological_sorted_vec.push_back(cur_course_num);
        	q.pop();
        	// find a range containing all the elements whose key is cur_course_num:
        	auto its = graph.equal_range(cur_course_num);
        	for (auto it = its.first; it != its.second; ++it) {
        		if ( --count_indegree[it->second] == 0 ) q.push(it->second);
        	} 
        }

        return topological_sorted_vec.size() == numCourses;
    }
};