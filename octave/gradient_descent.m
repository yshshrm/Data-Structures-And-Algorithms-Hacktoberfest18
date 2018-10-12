function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);
for iter = 1:num_iters
    pre=X*theta;
    sqr=(pre-y); 
    sqr2=(pre-y).*X(:,2);
    theta(1,1)=theta(1,1)-alpha * (1/m * sum(sqr));
    theta(2,1)=theta(2,1)-alpha * (1/m * sum(sqr2));
    J_history(iter) = computeCost(X, y, theta);
end
end


function J = computeCost(X, y, theta)
%COMPUTECOST Compute cost for linear regression
%   J = COMPUTECOST(X, y, theta) computes the cost of using theta as the
%   parameter for linear regression to fit the data points in X and y
m = length(y); % number of training examples
pre=X*theta;
sqr=(pre-y).^2;
J = 1/(2*m) * sum(sqr);
end
