function [data] = parseOF_Log(FileName, phrase)

fid = fopen(FileName, 'r');
if fid == -1
   error('Cannot open file: %s', FileName);
end

data = [];

while ~feof(fid)
    
    Line = fgetl(fid);
    expInclude = strcat('\w*',phrase,'\w*');
    
    if ~isempty(regexpi(Line,expInclude))
        data = [data; str2num(Line(size(phrase,2):size(Line,2)))];
    end
   
end

fclose(fid);
end