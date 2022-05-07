// https://www.codingninjas.com/codestudio/problems/find-conflicting-meetings_1170047?leftPanelTab=1

//---------------O(nlogn),O(n)----------------
//---------------------Code-------------------
vector<int> findConflictingMeetings(vector<vector< int >> &m) {
	int n=m.size();
	vector<int> cm(n, -1);
	for(int i=0; i<n; i++){
		m[i].push_back(i);
	}
	sort(m.begin(), m.end());
	
	int mb = m[0][1], mib=m[0][2];
	for(int i=1; i<n; i++){
		if(m[i][0] < mb){
			cm[m[i][2]] = mib+1;
			cm[mib] = m[i][2]+1;
		}
		if(m[i][1] > mb){
			mib = m[i][2];
			mb = m[i][1];
		}
	}
	return cm;
}
